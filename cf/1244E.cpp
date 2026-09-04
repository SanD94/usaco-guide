// https://codeforces.com/contest/1244/problem/E
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#define all(x) begin(x),end(x)

using ll = long long;

vector<ll> calc_diff(vector<ll>& arr) {
    int n = (int)arr.size();
    vector<ll> res(n);
    for (int i = 1; i < n; i++) 
        res[i] = res[i] + i * abs(arr[i] - arr[i-1]) * 1LL;
    return res;
}

int main() {
    int n;
    ll k;
    vector<ll> arr;
    cin >> n >> k;
    copy_n(istream_iterator<ll>(cin), n, back_inserter(arr));
    sort(all(arr));

    vector<ll> rev_arr = arr;
    reverse(all(rev_arr));

    auto diff_left = calc_diff(arr);
    auto diff_right = calc_diff(rev_arr);
    reverse(all(diff_right));

    auto eval = [&](ll m) {
        for (int i = 0; i < n; i++) {
            ll sum = diff_left[i];
            ll right_b = arr[i] + m;
            auto low = lower_bound(all(arr), right_b);
            int right_idx = distance(low, begin(arr));
            sum += diff_right[right_idx] + (arr[right_idx] - right_b) * (n - right_idx - 1);

            if (sum <= k) return true;
        }

        return false;
    };

    ll l = 0, r = 1e9;
    while (l < r) {
        ll m = l + (r - l) / 2;
        if (eval(m)) r = m;
        else l = m + 1;
    }
    
    cout << l << endl;
    
    return 0;
}



