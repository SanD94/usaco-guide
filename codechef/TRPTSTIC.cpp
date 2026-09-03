// https://www.codechef.com/problems/TRPTSTIC
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

using ll = long long;

vector<vector<ll>> calc_prefix(vector<vector<ll>>& arr, int n, int m) {
    vector<vector<ll>> res(n+1, vector<ll>(m+1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i+1][j+1] = arr[i][j] + res[i][j+1] + res[i+1][j] - res[i][j];
    return res;
}

int main() {
    int t, n, m;
    ll k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<vector<ll>> hotel(n, vector<ll>(m));

        for (int i = 0; i < n; i++)
            copy_n(istream_iterator<ll>(cin), m, begin(hotel[i]));

        auto prefix = calc_prefix(hotel, n, m);
        auto get_sum = [&](int xl, int yb, int xr, int yt) {
            return prefix[xr][yt] - prefix[xr][yb] - prefix[xl][yt] + prefix[xl][yb];
        };

        int l = 0, r = max(n, m) + 1;
        while (l < r) {
            int d = l + (r - l) / 2;
            bool found = false;

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    if (hotel[i][j] == 0) continue;
                    int xl = max(i - d, 0), xr = min(i + d, n - 1);
                    int yb = max(j - d, 0), yt = min(j + d, m - 1);

                    ll cur_sum = get_sum(xl, yb, xr + 1, yt + 1);
                    if (cur_sum > k) found = true;
                }

            if (found) r = d;
            else l = d + 1;
        }

        if (l == max(n, m) + 1) l = -1; 
        cout << l << endl;
    }

    return 0;
}
