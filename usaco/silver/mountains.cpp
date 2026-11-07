// https://usaco.org/index.php?page=viewproblem2&cpid=896
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct mountain {
    ll base, peak;
    friend istream& operator>>(istream& is, mountain& m) {
        return is >> m.base >> m.peak;
    }
};

struct mbase {
    ll left, right;
    friend bool operator<(const mbase& lhs, const mbase& rhs) {
        if (lhs.left == rhs.left) return rhs.right < lhs.right;
        return lhs.left < rhs.left;
    }
};


int main() {
    set_io("mountains");

    int n;
    vector<mountain> m;
    vector<mbase> bases;

    cin >> n;
    copy_n(istream_iterator<mountain>(cin), n, back_inserter(m));

    for (int i = 0; i < n; i++) {
        auto [b, p] = m[i];
        bases.push_back({ b-p, b+p });
    }

    sort(all(bases));
    int res = 1;

    int cur_r = bases[0].right;

    for (int i = 1; i < n; i++) 
        if (bases[i].right > cur_r) {
            res ++;
            cur_r = bases[i].right;
        }

    cout << res << endl;
    return 0;
}

