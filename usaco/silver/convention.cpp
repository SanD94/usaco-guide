// https://usaco.org/index.php?page=viewproblem2&cpid=858
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

bool manage(vector<int> &cows, int bus, int lim, int t) {

    int sz = (int)cows.size(), i = 0;

    while (i < sz) {
        int j = i;
        while(cows[j] - cows[i] <= t && j - i < lim && j < sz) j++;
        if (bus == 0) return false;
        bus --;
        i = j;
    }
    return i == sz;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set_io("convention");
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> cows(n);

    copy_n(istream_iterator<int>(cin), n, begin(cows));
    sort(all(cows));
    int lo = 0, hi = 1e9;

    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (manage(cows, m, c, mi))
            hi = mi;
        else lo = mi + 1;
    }


    cout << lo << endl;
    return 0;
}


