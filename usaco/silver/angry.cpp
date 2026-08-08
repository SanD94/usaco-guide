// https://usaco.org/index.php?page=viewproblem2&cpid=594
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool manage(vector<int> &bales, int cow, int r) {

    int sz = (int)bales.size(), i = 0;

    while (i < sz) {
        int j = i;
        while(bales[j] - bales[i] <= 2*r && j < sz) j++;
        if (cow == 0) return false;
        cow --;
        i = j;
    }
    return i == sz;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set_io("angry");
    int n, k;
    cin >> n >> k;
    vector<int> bales(n);

    copy_n(istream_iterator<int>(cin), n, begin(bales));
    sort(all(bales));
    int lo = 0, hi = 1e9;

    while (lo < hi) {
        int mi = lo + (hi - lo) / 2;
        if (manage(bales, k, mi))
            hi = mi;
        else lo = mi + 1;
    }


    cout << lo << endl;
    return 0;
}



