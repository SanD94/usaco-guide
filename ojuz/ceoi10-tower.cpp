// https://oj.uz/problem/view/CEOI10_tower
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


using lli = long long int;
constexpr lli MOD{static_cast<lli>(1e9) + 9};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    lli d;
    cin >> n >> d;
    vector<lli> tower(n);

    copy_n(istream_iterator<int>(cin), n, tower.begin());
    sort(begin(tower), end(tower));

    lli res = 1, l = 0;
    for(int r = 0; r < n; r++) {
        while (l < n && tower[l] + d < tower[r]) l++;
        res = ((r - l + 1) * res) % MOD;
    }

    cout << res << endl;
    return 0;
}

