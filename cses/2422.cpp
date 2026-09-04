// https://cses.fi/problemset/task/2422
#include <iostream>
using namespace std;

using ll = long long;
int main() {
    ll n;
    cin >> n;
    ll med = n * n / 2 + 1;

    ll l = 1, r = n * (n + 1) / 2;
    while (l < r) {
        ll m = l + (r - l) / 2;
        ll rm = 0;
        for (ll i = 1; i <= n; i++)
            rm += min(n, m / i);

        if (rm < med)  l = m + 1;
        else r = m;
    }

    cout << l << endl;
    return 0;
}

