// https://codeforces.com/problemset/problem/1000/C
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

struct segment {
    ll x;
    int dir;
    friend bool operator<(const segment& lhs, const segment& rhs) {
        if (lhs.x == rhs.x) return lhs.dir < rhs.dir;
        return lhs.x < rhs.x;
    }
};

int main() {
    int n;
    vector<segment> segments;
    cin >> n;
    vector<ll> res(n+1);

    ll l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        segments.push_back({l, 1});
        segments.push_back({r + 1, -1});
    }

    sort(all(segments));

    ll cur = segments[0].x, cur_cnt = 0;
    for (size_t i = 0; i < segments.size(); i++) {
        auto [next, dcnt] = segments[i];
        if (next != cur) 
            res[cur_cnt] += (next - cur);
        cur_cnt += dcnt;
        cur = next;
    }

    copy(res.begin() + 1, res.end(), ostream_iterator<ll>(cout, " "));

    return 0;
}


