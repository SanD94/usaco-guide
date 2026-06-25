// https://usaco.org/index.php?page=viewproblem2&cpid=595
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main() {
    set_io("div7");
    int n;
    cin >> n;
    vector<int> cows;
    copy_n(istream_iterator<int>(cin), n, back_inserter(cows));

    vector<int> sums(n+1);
    for(int i = 0; i < n; i++)
        sums[i + 1] = (sums[i] + cows[i]) % 7;

    vector<int> mn_cnt(7, 100'000), mx_cnt(7, 0);
    for(int i = 0; i <= n; i++) {
        mn_cnt[sums[i]] = min(mn_cnt[sums[i]], i);
        mx_cnt[sums[i]] = max(mx_cnt[sums[i]], i);
    }


    int res = -1;
    for (int i = 0; i < 7; i++) res = max(res, mx_cnt[i] - mn_cnt[i]);

    if (res == -1) res = 0;
    cout << res << endl;


    return 0;
}


