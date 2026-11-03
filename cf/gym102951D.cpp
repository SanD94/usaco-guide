// https://codeforces.com/gym/102951/problem/D
#include <iostream>
#include <iterator>
#include <queue>
#include <map>
using namespace std;

using ll = long long;

struct change {
    ll val;
    int idx;
    friend bool operator<(const change& lhs, const change& rhs) {
        if (lhs.idx == rhs.idx) return lhs.val < rhs.val;
        return lhs.idx < rhs.idx;
    }

    friend bool operator>(const change& lhs, const change& rhs) {
        return rhs < lhs;
    }
};

int main() {
    int N, Q;
    int r, l;
    ll val;

    cin >> N >> Q;
    priority_queue<change, vector<change>, greater<>> pq;
    map<int, ll> changes;
    map<int, ll> prefix;

    for (int i = 0; i < N; i++) {
        cin >> l >> r >> val;
        pq.push({ val, l });
        pq.push({ -val, r });
    }

    int cur = 0;
    prefix[0] = 0;
    changes[0] = 0;
    while (!pq.empty()) {
        auto [cur_val, next] = pq.top();
        pq.pop();
        if (cur != next) {
            prefix[next] += (next - cur) * changes[cur] + prefix[cur];
            changes[next] = changes[cur];
        }
        cur = next;
        changes[cur] += cur_val;
    }
    prefix[1e9 + 1] = prefix[cur];
    changes[1e9 + 1] = 0;

    auto eval = [&changes, &prefix](int l, int r) {
        auto l_it = prev(changes.upper_bound(l));
        auto r_it = changes.lower_bound(r);

        int lidx = l_it->first;
        int ridx = r_it->first;

        auto l_remove = (l - lidx) * l_it->second;
        auto r_remove = (ridx - r) * prev(r_it)->second;


        return prefix.at(ridx) - prefix.at(lidx) - l_remove - r_remove;
    };

    for (int i = 0; i < Q; i++) {
        cin >> l >> r;
        cout << eval(l, r) << endl;
    }

    return 0;

}
