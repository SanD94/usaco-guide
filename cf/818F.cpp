// https://codeforces.com/problemset/problem/818/F
#include <algorithm>
#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;

        auto less_component = [n](ll x) {
            return 2 * (x - 1) < (n - x + 1) * (n - x);
        };

        auto f = [n](ll x) {
            return (x - 1) + min((n - x + 1) * (n - x) / 2, x - 1);
        };

        ll l = 0, r = n;
        while (l < r) {
            ll m = l + (r - l + 1) / 2;
            if (less_component(m)) l = m;
            else r = m - 1;
        }
        cout << max(f(l), f(l+1)) << endl;
    }

    return 0;
}


