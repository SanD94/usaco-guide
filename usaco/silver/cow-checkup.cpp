// https://usaco.org/index.php?page=viewproblem2&cpid=1470
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


using lli = long long int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n+1), b(n+1);

    copy_n(istream_iterator<int>(cin), n, a.begin() + 1);
    copy_n(istream_iterator<int>(cin), n, b.begin() + 1);

    vector<vector<int>> da(n+1), db(n+1);

    for (int i = 1; i <= (n + 1) / 2; i++) {
        int l = i;
        int r = n - i + 1;

        da[a[l]].push_back(i);
        db[b[l]].push_back(i);

        if (l != r) {
            da[a[r]].push_back(i);
            db[b[r]].push_back(i);
        }
    }

    lli res = 0;

    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            res += 1LL * (i - 1) * i / 2;
            res += 1LL * (n - i) * (n - i + 1) / 2;
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<int>& dai = da[i]; 
        vector<int>& dbi = db[i];

        size_t l = 0;
        lli pre_sum = 0;
        for (auto d_cow: dai) {
            while(l < dbi.size() && dbi[l] <= d_cow) {
                pre_sum += dbi[l];
                l++;
            }
            res += pre_sum + 1LL * d_cow * (dbi.size() - l);
        }
    }

    cout << res << endl;
    return 0;
}
