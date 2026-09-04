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
        res[i] = res[i - 1] + i * abs(arr[i] - arr[i - 1]);
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
        int right = 0;
        for (int i = 0; i < n; i++) {
            ll left_b = arr[i];
            ll right_b = left_b + m;
            while (right < n && arr[right] <= right_b) right++;

            ll sum = diff_left[i];
            if (right < n)
                sum += diff_right[right] + (arr[right] - right_b) * (n - right);

            if (sum <= k) return true;
        }

        int left = 0;
        for (int i = 0; i < n; i++) {
            ll right_b = arr[i];
            ll left_b = right_b - m;
            while (left < n && arr[left] < left_b) left++;

            ll sum = diff_right[i];
            sum += diff_left[left] - (arr[left] - left_b) * left;

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

