// https://usaco.org/index.php?page=viewproblem2&cpid=1377
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;
const ll INF = 2e9 + 10LL;

// keep only the first road whenever the parity changes. 
vector<ll> turn_points(const vector<ll>& roads) {
    vector<ll> parity;
    for (ll x : roads)
        if (parity.empty() || x % 2 != parity.back() % 2)
            parity.push_back(x);
    return parity;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> vert, hori;
    int n, q;
    cin >> n >> q;

    char ch;
    ll pos;
    for (int i = 0; i < n; i++) {
        cin >> ch >> pos;
        (ch == 'V' ? vert : hori).push_back(pos);
    }

    sort(all(vert));
    sort(all(hori));
    vector<ll> vert_turns = turn_points(vert);
    vector<ll> hori_turns = turn_points(hori);
    vector<int> pair_indices(n);
    iota(all(pair_indices), 0);

    while (q--) {
        ll x, y, t;
        cin >> x >> y >> t;

        // elapsed time has the same parity as (x + y) - start_sum.
        const ll start_parity = (x + y) % 2;

        auto move_to = [&](ll& pos, ll target) {
            ll dist = target - pos;
            if (dist >= t) {
                pos += t;
                t = 0;
                return false;
            }
            pos = target;
            t -= dist;
            return true;
        };

        // the cow goes north if it is on a vertical road. 
        bool move_up = binary_search(all(vert), x);
        const vector<ll>& roads = move_up ? hori : vert;
        const vector<ll>& turns = move_up ? hori_turns : vert_turns;
        ll& cur_pos = move_up ? y : x;
        ll fix_pos = move_up ? x : y;

        // raw roads are needed, might be inside a parity block.
        auto next = lower_bound(all(roads), cur_pos);
        ll next_pos = next == roads.end() ? INF : *next;
        bool same_parity = (next_pos + fix_pos) % 2 == start_parity;
        if (next_pos != INF && same_parity == move_up) {
            next = upper_bound(all(turns), next_pos);
            next_pos = next == turns.end() ? INF : *next;
        }
        if (!move_to(cur_pos, next_pos)) {
            cout << x << " " << y << '\n';
            continue;
        }
        move_up = !move_up;

        // every pair is a first leg followed 
        // by a second leg, regardless of the direction
        const vector<ll>& f_turns = move_up ? hori_turns : vert_turns;
        const vector<ll>& s_turns = move_up ? vert_turns : hori_turns;
        ll& f_pos = move_up ? y : x;
        ll& s_pos = move_up ? x : y;

        int f_idx = upper_bound(all(f_turns), f_pos) - f_turns.begin();
        int s_idx = upper_bound(all(s_turns), s_pos) - s_turns.begin();
        int max_pairs = min((int)f_turns.size() - f_idx,
                            (int)s_turns.size() - s_idx);

        auto first_unreachable = upper_bound(
            pair_indices.begin(), pair_indices.begin() + max_pairs, t,
            [&](ll cur_t, int pair_idx) {
                ll distance = f_turns[f_idx + pair_idx] - f_pos +
                              s_turns[s_idx + pair_idx] - s_pos;
                return cur_t < distance;
            });
        int done_pairs = first_unreachable - pair_indices.begin();

        if (done_pairs > 0) {
            int last_pair = done_pairs - 1;
            move_to(f_pos, f_turns[f_idx + last_pair]);
            move_to(s_pos, s_turns[s_idx + last_pair]);
            f_idx += done_pairs;
            s_idx += done_pairs;
        }

        // finish the incomplete pair
        next_pos = f_idx == (int)f_turns.size() ? INF : f_turns[f_idx];
        if (!move_to(f_pos, next_pos)) {
            cout << x << " " << y << '\n';
            continue;
        }
        next_pos = s_idx == (int)s_turns.size() ? INF : s_turns[s_idx];
        move_to(s_pos, next_pos);
        cout << x << " " << y << '\n';
    }

    return 0;
}
