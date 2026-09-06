// https://codeforces.com/gym/104468/problem/H
#include <iostream>
#include <vector>
using namespace std;


using ll = long long;
const int MAXN = 2e5+1;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> exclude(MAXN);
    ll tot = 0;

    vector<vector<ll>> es(MAXN, vector<ll>(1));
    for (int i = 0; i < n; i++)  cin >> arr[i];
    for (int i = 0; i < n; i++) {
        cin >> c;
        vector<ll>& cur = es[c];
        cur.push_back(cur.back() + arr[i]);
    }

    int t;
    cin >> t;
    while (t--) {
        int q, col;
        ll num;
        cin >> q >> col >> num;

        if (q == 1) {
            tot += num;
            exclude[col] += num;
        } else {
            vector<ll>& cur = es[col];
            int l = 0, r = cur.size() - 1;
            while (l < r) {
                int m = l + (r - l + 1) / 2;
                if (cur[m] + m * (tot - exclude[col]) <= num) l = m;
                else r = m - 1;
            }

            cout << l << "\n";
        }
    }
    
    return 0;
}
