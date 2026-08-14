// https://usaco.org/index.php?page=viewproblem2&cpid=991
#include <iostream>
#include <tuple>

using namespace std;

using ll = long long;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

tuple<ll, ll> use_x(ll n, ll m, ll x) {
    ll res = 0;
    ll t = n / x;
    while (m < t) {
        ll next = t * x;
        ll cur_step = (n - next) / t + 1;
        res += cur_step;
        n -= cur_step * t;
        t = n / x;
    }

    return {n, res};
}


bool pass(ll n, ll k, ll m, ll x) {
    auto [left, res] = use_x(n, m, x);
    return left / m + (left % m != 0) + res <= k;
}


int main() {
    set_io("loan");

    ll n, k, m;

    cin >> n >> k >> m;
    ll l = 0, r = n;
    while (l < r) {
        ll mid = (l + r + 1) / 2;
        if (!pass(n, k, m, mid)) r = mid - 1;
        else l = mid;
    }

    cout << l << endl;
    
    return 0;
}
