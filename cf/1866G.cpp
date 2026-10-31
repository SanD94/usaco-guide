// https://codeforces.com/contest/1866/problem/G
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

struct cis {
    int l, r, val;

    friend bool operator<(const cis& lhs, const cis& rhs) {
        return tie(lhs.r, lhs.l, lhs.val) < tie(rhs.r, rhs.l, rhs.val);
    }
    
    friend bool operator>(const cis& lhs, const cis& rhs) {
        return rhs < lhs;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> cs, is;
    vector<cis> elems;

    cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(cs));
    copy_n(istream_iterator<int>(cin), n, back_inserter(is));

    for (int i = 0; i < n; i++)
        elems.push_back({ max(0, i - is[i]), min(n - 1, i + is[i]), cs[i] });

    sort(all(elems), [](const cis& a, const cis& b) {
        return a.l < b.l;
    });

    int l = 0, r = 1e9;

    while (l < r) {
        int m = l + (r - l) / 2;
        priority_queue<cis, vector<cis>, greater<>> Q;
        bool is_good = true;

        int next = 0;
        for (int cur_idx = 0; cur_idx < n && is_good; cur_idx++) {
            while (next < n && elems[next].l <= cur_idx) {
                if (elems[next].val > 0) Q.push(elems[next]);
                next++;
            }

            int space = m;
            while (space > 0 && !Q.empty()) {
                auto cur = Q.top(); Q.pop();
                int take = min(space, cur.val);
                space -= take;
                cur.val -= take;
                if (cur.val > 0) Q.push(cur);
            }
            if (!Q.empty() && Q.top().r <= cur_idx) is_good = false;
        }

        if (is_good) r = m;
        else l = m + 1;
    }

    cout << l << endl;
    

    return 0;
}

