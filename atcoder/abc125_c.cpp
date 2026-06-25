// https://atcoder.jp/contests/abc125/tasks/abc125_c
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using lli = long long int;

int gcd(int a, int b) {
    if (a == 0 || b == 0) return max(a, b);
    if (a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    int n, res = 0;
    cin >> n;
    vector<int> nums(n), left(n+2), right(n+2);

    copy_n(istream_iterator<int>(cin), n, begin(nums));
    for (int i = 0; i < n; i++)
        left[i + 1] = gcd(nums[i], left[i]);
    for (int i = n; i >= 1; i--)
        right[i] = gcd(nums[i-1], right[i + 1]);

    for (int i = 1; i <= n; i++)
        res = max(res, gcd(left[i-1], right[i+1]));

    cout << res << endl;

    return 0;
}

