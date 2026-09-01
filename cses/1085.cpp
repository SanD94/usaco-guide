// https://cses.fi/problemset/task/1085
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

#define all(x) begin(x),end(x)

using ll = long long;
const ll MX = 1e18+10;

int div_num(vector<int>& nums, ll sum) {
    int res = 1;
    ll cur_sum = 0;

    for (auto num: nums) {
        if (cur_sum + num > sum) {
            res ++;
            cur_sum = 0;
        }
        cur_sum += num;
    }
    return res;
}



int main() {
    int n, k;
    vector<int> nums;

    cin >> n >> k;
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));

    ll l = *max_element(all(nums));
    ll r = MX;
    while (l < r) {
        ll m = l + (r - l) / 2;
        if (div_num(nums, m) <= k) r = m;
        else l = m + 1;
    }

    cout << l << endl;

    return 0;
}

