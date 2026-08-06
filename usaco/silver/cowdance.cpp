// https://usaco.org/index.php?page=viewproblem2&cpid=690
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set_io("cowdance");
    int n, t;
    cin >> n >> t;
    vector<int> dance(n), res(n);
    iota(all(res), 1);

    copy_n(istream_iterator<int>(cin), n, begin(dance));

    auto nice_dance = lower_bound(all(res), t, [&](int m, int t) {
        int cur_t = 0;
        priority_queue<int, vector<int>, greater<>> Q;
        for (int i = 0; i < n; i++) {
            if ((int)Q.size() < m) {
                Q.push(dance[i]);
                continue;
            }
            int left = Q.top();
            Q.pop();
            Q.push(dance[i] + left);
        }
        while (!Q.empty()) {
            cur_t = max(cur_t, Q.top());
            Q.pop();
        }
        
        return t < cur_t;
    });

    cout << *nice_dance << endl;

    return 0;
}

