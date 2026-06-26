// https://cses.fi/problemset/task/1643
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

using lli = long long int;

int main() {
    int n;
    vector<lli> nums;
    lli res = -1e9, cur = 0;
    cin >> n;
    copy_n(istream_iterator<lli>(cin), n, back_inserter(nums));
    for (int i = 0; i < n; i++) {
        cur += nums[i];
        res = max(res, cur);
        if (cur < 0) cur = 0;
    }
    cout << res << endl;
    return 0;
}

