// https://usaco.org/index.php?page=viewproblem2&cpid=738
#include <iostream>
#include <vector>
#include <iterator>
#include <tuple>
#include <algorithm>
using namespace std;

using lli = long long int;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct machine {
    lli milk;
    lli count;
    friend bool operator<(const machine &lhs, const machine &rhs) {
        return tie(lhs.milk, lhs.count) < tie(rhs.milk, rhs.count);
    }

    friend istream &operator>>(istream &is, machine &m) {
        return is >> m.count >> m.milk;
    }
};

int main() {
    set_io("pairup");
    int n;
    vector<machine> cows;

    cin >> n;
    copy_n(istream_iterator<machine>(cin), n, back_inserter(cows));

    sort(begin(cows), end(cows));
    int l = 0, r = n - 1;
    lli res = 0;

    while (l <= r) {
        lli use = min(cows[l].count, cows[r].count);
        cows[l].count -= use;
        cows[r].count -= use;

        res = max(res, cows[l].milk + cows[r].milk);
        if (cows[l].count <= 0) l++;
        if (cows[r].count <= 0) r--;
    }


    cout << res << endl;
    return 0;
}


