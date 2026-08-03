// https://codeforces.com/contest/1744/problem/F
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


using lli = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, p;
        lli res = 1;

        cin >> n;
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            cin >> p;
            pos[p] = i;
        }

        int l = pos[0], r = pos[0];
        for (int i = 1; i < n; i++) {
            if (l <= pos[i] && pos[i] <= r) continue;
            while (pos[i] < l) {
                res += max(min(l + 2*i - 1, n - 1) - r + 1, 0);
                l--;
            }

            while (r < pos[i]) {
                res += max(l - max(r - 2*i + 1, 0) + 1, 0);
                r++;
            }
        }
        cout << res << "\n";
    }



    return 0;
}
