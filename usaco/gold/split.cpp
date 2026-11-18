// https://usaco.org/index.php?page=viewproblem2&cpid=645
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

struct cow {
    int idx;
    ll x, y;
};

bool comp_x(const cow& lhs, const cow& rhs) {
    return tie(lhs.x, lhs.y) < tie(rhs.x, rhs.y);
}

bool comp_y(const cow& lhs, const cow& rhs) {
    return tie(lhs.y, lhs.x) < tie(rhs.y, rhs.x);
}

bool rev_comp_y(const cow& lhs, const cow& rhs) {
    return comp_y(rhs, lhs);
}

ll eval_cows(vector<cow>& cows, int n) {
    ll res = 1e18;


    sort(all(cows), comp_x);
    for(int i = 0; i < n; i++) cows[i].idx = i;

    priority_queue<cow, vector<cow>, decltype(&comp_y)>
        left_top(comp_y, vector<cow>{}), 
        right_top(comp_y, cows);
    priority_queue<cow, vector<cow>, decltype(&rev_comp_y)> 
        left_bottom(rev_comp_y, vector<cow>{}), 
        right_bottom(rev_comp_y, cows);


    for (int i = 0; i < n; i++) {
        if (i > 0 && cows[i].x == cows[i-1].x) {
            left_top.push(cows[i]); left_bottom.push(cows[i]);
            continue;
        }

        auto [idx_br, right_beg, yrb] = cows[i];
        auto [idx_er, right_end, yre] = cows[n-1];
        while(right_top.top().idx < i) right_top.pop();
        while(right_bottom.top().idx < i) right_bottom.pop();
        ll right_res = (right_end - right_beg) * (right_top.top().y - right_bottom.top().y);

        ll left_res = 0;
        if (i != 0) {
            auto [idx_bl, left_beg, ylb] = cows[0];
            auto [idx_el, left_end, yle] = cows[i-1];
            left_res = (left_end - left_beg) * (left_top.top().y - left_bottom.top().y);
        }
        left_top.push(cows[i]); left_bottom.push(cows[i]);
        
        res = min(res, right_res + left_res);
    }

    return res;
}


void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    set_io("split");

    int n;
    ll x, y;
    vector<cow> cows;
    ll xl = 1e9, xr = 0, yb = 1e9, yt = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        cows.push_back({i, x, y});
        xl = min(xl, x); xr = max(xr, x);
        yb = min(yb, y); yt = max(yt, y);
    }

    ll total = (xr - xl) * (yt - yb);
    ll saved = total;

    saved = min(saved, eval_cows(cows, n));
    for(int i = 0; i < n; i++) {
        auto [idx, cx, cy] = cows[i];
        cows[i] = cow{idx, cy, cx};
    }
    saved = min(saved, eval_cows(cows, n));

    cout << total - saved << endl;
    return 0;
}

