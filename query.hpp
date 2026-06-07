#pragma once

#include <cstddef>
#include <functional>
#include <iterator>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

namespace query {

namespace detail {

struct transform_tag {};
struct terminal_tag {};

template <typename T>
struct is_reference_wrapper : std::false_type {};

template <typename T>
struct is_reference_wrapper<std::reference_wrapper<T>> : std::true_type {};

template <typename T>
struct unwrap_ref {
    using type = T;

    static T& get(T& value) {
        return value;
    }
};

template <typename T>
struct unwrap_ref<std::reference_wrapper<T>> {
    using type = T;

    static T& get(std::reference_wrapper<T> value) {
        return value.get();
    }
};

template <typename T>
using unwrapped_t = typename unwrap_ref<typename std::decay<T>::type>::type;

template <typename Range>
using range_value_t = typename std::decay<decltype(*std::begin(std::declval<Range&>()))>::type;

template <typename Source>
using source_value_t = range_value_t<unwrapped_t<Source>>;

template <typename Op>
using is_transform = std::is_base_of<transform_tag, typename std::decay<Op>::type>;

template <typename Op>
using is_terminal = std::is_base_of<terminal_tag, typename std::decay<Op>::type>;

template <typename It, typename End>
struct iterator_range {
    It first;
    End last;

    It begin() {
        return first;
    }

    End end() {
        return last;
    }
};

struct counted_sentinel {};

template <typename It>
struct counted_iterator {
    It it;
    std::size_t left;

    decltype(auto) operator*() {
        return *it;
    }

    counted_iterator& operator++() {
        ++it;
        --left;
        return *this;
    }

    bool operator!=(counted_sentinel) const {
        return left > 0;
    }
};

template <typename It>
struct counted_range {
    It first;
    std::size_t n;

    counted_iterator<It> begin() {
        return {first, n};
    }

    counted_sentinel end() {
        return {};
    }
};

} // namespace detail

template <typename F>
struct map_op : detail::transform_tag {
    using kind = std::integral_constant<int, 0>;
    F f;
};

template <typename Pred>
struct filter_op : detail::transform_tag {
    using kind = std::integral_constant<int, 1>;
    Pred pred;
};

template <typename F>
struct flat_map_op : detail::transform_tag {
    using kind = std::integral_constant<int, 2>;
    F f;
};

namespace detail {

template <typename T, typename... Ops>
struct output_type {
    using type = T;
};

template <typename T, typename F, typename... Rest>
struct output_type<T, map_op<F>, Rest...> {
    using next = typename std::decay<decltype(std::declval<F>()(std::declval<T>()))>::type;
    using type = typename output_type<next, Rest...>::type;
};

template <typename T, typename Pred, typename... Rest>
struct output_type<T, filter_op<Pred>, Rest...> {
    using type = typename output_type<T, Rest...>::type;
};

template <typename T, typename F, typename... Rest>
struct output_type<T, flat_map_op<F>, Rest...> {
    using sub_range = decltype(std::declval<F>()(std::declval<T>()));
    using next = range_value_t<sub_range>;
    using type = typename output_type<next, Rest...>::type;
};

template <std::size_t I, typename Tuple, typename X, typename Emit>
bool apply_ops(Tuple& ops, X&& x, Emit& emit);

template <std::size_t I, typename Tuple, typename X, typename Emit>
bool apply_kind(std::integral_constant<int, 0>, Tuple& ops, X&& x, Emit& emit) {
    auto& op = std::get<I>(ops);
    auto y = op.f(std::forward<X>(x));
    return apply_ops<I + 1>(ops, std::move(y), emit);
}

template <std::size_t I, typename Tuple, typename X, typename Emit>
bool apply_kind(std::integral_constant<int, 1>, Tuple& ops, X&& x, Emit& emit) {
    auto& op = std::get<I>(ops);
    if (!op.pred(x)) return true;
    return apply_ops<I + 1>(ops, std::forward<X>(x), emit);
}

template <std::size_t I, typename Tuple, typename X, typename Emit>
bool apply_kind(std::integral_constant<int, 2>, Tuple& ops, X&& x, Emit& emit) {
    auto& op = std::get<I>(ops);
    auto sub = op.f(std::forward<X>(x));
    for (auto&& y : sub) {
        if (!apply_ops<I + 1>(ops, std::forward<decltype(y)>(y), emit)) return false;
    }
    return true;
}

template <std::size_t I, typename Tuple, typename X, typename Emit>
bool apply_ops(Tuple& ops, X&& x, Emit& emit) {
    if constexpr (I == std::tuple_size<typename std::decay<Tuple>::type>::value) {
        return emit(std::forward<X>(x));
    } else {
        using Op = typename std::tuple_element<I, typename std::decay<Tuple>::type>::type;
        return apply_kind<I>(typename Op::kind{}, ops, std::forward<X>(x), emit);
    }
}

} // namespace detail

template <typename Source, typename... Ops>
class pipeline {
public:
    using output_value_type = typename detail::output_type<
        detail::source_value_t<Source>, Ops...>::type;

    pipeline(Source source, std::tuple<Ops...> ops = {})
        : source_(std::move(source)), ops_(std::move(ops)) {}

    template <typename Op>
    auto append(Op op) && {
        using CleanOp = typename std::decay<Op>::type;
        return pipeline<Source, Ops..., CleanOp>(
            std::move(source_),
            std::tuple_cat(std::move(ops_), std::make_tuple(std::move(op))));
    }

    template <typename Out = void>
    auto execute() & {
        return materialize<Out>(*this);
    }

    template <typename Out = void>
    auto execute() && {
        return materialize<Out>(std::move(*this));
    }

    template <typename Emit>
    bool for_each(Emit&& emit) & {
        auto& range = detail::unwrap_ref<Source>::get(source_);
        for (auto&& x : range) {
            if (!detail::apply_ops<0>(ops_, x, emit)) return false;
        }
        return true;
    }

    template <typename Emit>
    bool for_each(Emit&& emit) && {
        auto& range = detail::unwrap_ref<Source>::get(source_);
        for (auto&& x : range) {
            if constexpr (detail::is_reference_wrapper<Source>::value) {
                if (!detail::apply_ops<0>(ops_, x, emit)) return false;
            } else {
                if (!detail::apply_ops<0>(ops_, std::move(x), emit)) return false;
            }
        }
        return true;
    }

private:
    template <typename Out, typename Q>
    static auto materialize(Q&& q) {
        using Result = typename std::conditional<
            std::is_void<Out>::value,
            std::vector<output_value_type>,
            Out>::type;

        Result result;
        std::forward<Q>(q).for_each([&](auto&& x) {
            result.push_back(std::forward<decltype(x)>(x));
            return true;
        });
        return result;
    }

    Source source_;
    std::tuple<Ops...> ops_;
};

template <typename Range>
auto from(Range&& range) {
    using Source = typename std::decay<Range>::type;
    return pipeline<Source>(std::forward<Range>(range));
}

template <typename Range>
auto from_ref(Range& range) {
    return pipeline<std::reference_wrapper<Range>>(std::ref(range));
}

template <typename It, typename End>
auto from(It first, End last) {
    return pipeline<detail::iterator_range<It, End>>(
        detail::iterator_range<It, End>{std::move(first), std::move(last)});
}

template <typename It>
auto from_n(It first, std::size_t n) {
    return pipeline<detail::counted_range<It>>(
        detail::counted_range<It>{std::move(first), n});
}

template <typename F>
auto map(F f) {
    return map_op<typename std::decay<F>::type>{{}, std::move(f)};
}

template <typename Pred>
auto filter(Pred pred) {
    return filter_op<typename std::decay<Pred>::type>{{}, std::move(pred)};
}

template <typename F>
auto flat_map(F f) {
    return flat_map_op<typename std::decay<F>::type>{{}, std::move(f)};
}

template <typename Out = void>
struct execute_op : detail::terminal_tag {
    template <typename Q>
    auto operator()(Q&& q) const {
        return std::forward<Q>(q).template execute<Out>();
    }
};

template <typename Out = void>
auto execute() {
    return execute_op<Out>{};
}

template <typename OutIt>
struct copy_op : detail::terminal_tag {
    OutIt out;

    template <typename Q>
    OutIt operator()(Q&& q) {
        std::forward<Q>(q).for_each([&](auto&& x) {
            *out++ = std::forward<decltype(x)>(x);
            return true;
        });
        return out;
    }
};

template <typename OutIt>
auto copy(OutIt out) {
    return copy_op<OutIt>{{}, std::move(out)};
}

template <typename OutIt>
struct copy_n_op : detail::terminal_tag {
    std::size_t n;
    OutIt out;

    template <typename Q>
    OutIt operator()(Q&& q) {
        if (n == 0) return out;
        std::size_t copied = 0;
        std::forward<Q>(q).for_each([&](auto&& x) {
            if (copied == n) return false;
            *out++ = std::forward<decltype(x)>(x);
            ++copied;
            return copied < n;
        });
        return out;
    }
};

template <typename OutIt>
auto copy_n(std::size_t n, OutIt out) {
    return copy_n_op<OutIt>{{}, n, std::move(out)};
}

template <typename T, typename BinOp>
struct reduce_op : detail::terminal_tag {
    T init;
    BinOp op;

    template <typename Q>
    T operator()(Q&& q) {
        T acc = std::move(init);
        std::forward<Q>(q).for_each([&](auto&& x) {
            acc = op(std::move(acc), std::forward<decltype(x)>(x));
            return true;
        });
        return acc;
    }
};

template <typename T, typename BinOp>
auto reduce(T init, BinOp op) {
    return reduce_op<T, typename std::decay<BinOp>::type>{{}, std::move(init), std::move(op)};
}

template <typename T, typename BinOp>
struct inclusive_scan_op : detail::terminal_tag {
    T init;
    BinOp op;

    template <typename Q>
    std::vector<T> operator()(Q&& q) {
        std::vector<T> result;
        T acc = std::move(init);
        std::forward<Q>(q).for_each([&](auto&& x) {
            acc = op(std::move(acc), std::forward<decltype(x)>(x));
            result.push_back(acc);
            return true;
        });
        return result;
    }
};

template <typename T, typename BinOp>
auto inclusive_scan(T init, BinOp op) {
    return inclusive_scan_op<T, typename std::decay<BinOp>::type>{{}, std::move(init), std::move(op)};
}

template <typename T, typename BinOp>
struct exclusive_scan_op : detail::terminal_tag {
    T init;
    BinOp op;

    template <typename Q>
    std::vector<T> operator()(Q&& q) {
        std::vector<T> result;
        T acc = std::move(init);
        std::forward<Q>(q).for_each([&](auto&& x) {
            result.push_back(acc);
            acc = op(std::move(acc), std::forward<decltype(x)>(x));
            return true;
        });
        return result;
    }
};

template <typename T, typename BinOp>
auto exclusive_scan(T init, BinOp op) {
    return exclusive_scan_op<T, typename std::decay<BinOp>::type>{{}, std::move(init), std::move(op)};
}

template <typename Pred>
struct any_of_op : detail::terminal_tag {
    Pred pred;

    template <typename Q>
    bool operator()(Q&& q) {
        bool ans = false;
        std::forward<Q>(q).for_each([&](auto&& x) {
            if (pred(std::forward<decltype(x)>(x))) {
                ans = true;
                return false;
            }
            return true;
        });
        return ans;
    }
};

template <typename Pred>
auto any_of(Pred pred) {
    return any_of_op<typename std::decay<Pred>::type>{{}, std::move(pred)};
}

template <typename Pred>
struct all_of_op : detail::terminal_tag {
    Pred pred;

    template <typename Q>
    bool operator()(Q&& q) {
        bool ans = true;
        std::forward<Q>(q).for_each([&](auto&& x) {
            if (!pred(std::forward<decltype(x)>(x))) {
                ans = false;
                return false;
            }
            return true;
        });
        return ans;
    }
};

template <typename Pred>
auto all_of(Pred pred) {
    return all_of_op<typename std::decay<Pred>::type>{{}, std::move(pred)};
}

template <typename Pred>
struct none_of_op : detail::terminal_tag {
    Pred pred;

    template <typename Q>
    bool operator()(Q&& q) {
        bool ans = true;
        std::forward<Q>(q).for_each([&](auto&& x) {
            if (pred(std::forward<decltype(x)>(x))) {
                ans = false;
                return false;
            }
            return true;
        });
        return ans;
    }
};

template <typename Pred>
auto none_of(Pred pred) {
    return none_of_op<typename std::decay<Pred>::type>{{}, std::move(pred)};
}

template <typename KeyFn>
struct group_by_op : detail::terminal_tag {
    KeyFn key_fn;

    template <typename Q>
    auto operator()(Q&& q) {
        using V = typename std::decay<typename std::decay<Q>::type::output_value_type>::type;
        using K = typename std::decay<decltype(key_fn(std::declval<V>()))>::type;
        std::unordered_map<K, std::vector<V>> result;
        std::forward<Q>(q).for_each([&](auto&& x) {
            result[key_fn(x)].push_back(std::forward<decltype(x)>(x));
            return true;
        });
        return result;
    }
};

template <typename KeyFn>
auto group_by(KeyFn key_fn) {
    return group_by_op<typename std::decay<KeyFn>::type>{{}, std::move(key_fn)};
}

template <typename RangeB>
struct zip_op : detail::terminal_tag {
    RangeB b;

    template <typename Q>
    auto operator()(Q&& q) {
        using A = typename std::decay<typename std::decay<Q>::type::output_value_type>::type;
        using B = detail::range_value_t<RangeB>;
        std::vector<std::pair<A, B>> result;
        auto it = std::begin(b);
        auto last = std::end(b);
        std::forward<Q>(q).for_each([&](auto&& x) {
            if (it == last) return false;
            result.emplace_back(std::forward<decltype(x)>(x), *it++);
            return true;
        });
        return result;
    }
};

template <typename RangeB>
auto zip(RangeB&& b) {
    using Stored = typename std::decay<RangeB>::type;
    return zip_op<Stored>{{}, std::forward<RangeB>(b)};
}

template <typename RangeB, typename F>
struct zip_with_op : detail::terminal_tag {
    RangeB b;
    F f;

    template <typename Q>
    auto operator()(Q&& q) {
        using A = typename std::decay<typename std::decay<Q>::type::output_value_type>::type;
        using B = detail::range_value_t<RangeB>;
        using Out = typename std::decay<decltype(f(std::declval<A>(), std::declval<B>()))>::type;
        std::vector<Out> result;
        auto it = std::begin(b);
        auto last = std::end(b);
        std::forward<Q>(q).for_each([&](auto&& x) {
            if (it == last) return false;
            result.push_back(f(std::forward<decltype(x)>(x), *it++));
            return true;
        });
        return result;
    }
};

template <typename RangeB, typename F>
auto zip_with(RangeB&& b, F f) {
    using Stored = typename std::decay<RangeB>::type;
    return zip_with_op<Stored, typename std::decay<F>::type>{{}, std::forward<RangeB>(b), std::move(f)};
}

template <typename Source, typename... Ops, typename Op,
          typename std::enable_if<detail::is_transform<Op>::value, int>::type = 0>
auto operator|(pipeline<Source, Ops...> q, Op op) {
    return std::move(q).append(std::move(op));
}

template <typename Source, typename... Ops, typename Op,
          typename std::enable_if<detail::is_terminal<Op>::value, int>::type = 0>
auto operator|(pipeline<Source, Ops...> q, Op op) {
    return op(std::move(q));
}

} // namespace query
