// https://usaco.org/index.php?page=viewproblem2&cpid=1471
#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

using lli = long long int;


lli window_cost(const vector<lli> &prefix, int l, int n) {
    int half = n / 2;
    lli left = prefix[l + half] - prefix[l];
    lli right = prefix[l + n] - prefix[l + n - half];
    return right - left;
}


lli eval() {
    int n;
    lli m;
    cin >> n >> m;
    vector<lli> nums(n), circle(2 * n), prefix(2 * n + 1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        nums[i] %= m;
    }
    sort(begin(nums), end(nums));

    for (int i = 0; i < n; i++) {
        circle[i] = nums[i];
        circle[i + n] = nums[i] + m;
    }
    for (int i = 0; i < 2 * n; i++) prefix[i + 1] = prefix[i] + circle[i];

    lli res = LLONG_MAX;
    for (int i = 0; i < n; i++) res = min(res, window_cost(prefix, i, n));
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) cout << eval() << endl;
    return 0;
}
