// https://usaco.org/index.php?page=viewproblem2&cpid=1038
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)
using ll = long long;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool manage(vector<pair<ll, ll>> &graze, ll cow, ll d) {
    ll next_d = 0;
    for (auto &g : graze) {
        if (next_d < g.first) next_d = g.first;
        while (cow > 0 && next_d <= g.second) {
            cow--;
            next_d += d;
        }
    }

    return cow == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set_io("socdist");
    ll n, m;
    cin >> n >> m;
    vector<pair<ll, ll>> graze(m);

    for (auto &g : graze) cin >> g.first >> g.second;

    sort(all(graze));
    ll lo = 0, hi = 1e18;

    while (lo < hi) {
        ll mi = lo + (hi - lo + 1) / 2;
        if (!manage(graze, n, mi)) hi = mi - 1;
        else lo = mi;
    }


    cout << lo << endl;
    return 0;
}




