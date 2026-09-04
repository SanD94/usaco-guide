// https://codeforces.com/contest/1244/problem/E
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#define all(x) begin(x),end(x)

using ll = long long;

int main() {
    int n;
    ll k;
    vector<ll> arr;
    cin >> n >> k;
    copy_n(istream_iterator<ll>(cin), n, back_inserter(arr));
    sort(all(arr));

    vector<ll> pref(n + 1);
    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + arr[i];

    auto get_sub_sum = [&](int b, int e) {
        return pref[e] - pref[b];
    };

    auto eval = [&](ll m) {
        int right = 0;
        for (int i = 0; i < n; i++) {
            ll left_b = arr[i];
            ll right_b = left_b + m;
            while (right < n && arr[right] <= right_b) right++;

            ll sum = left_b * i - get_sub_sum(0, i);
            sum += get_sub_sum(right, n) - right_b * (n - right);

            if (sum <= k) return true;
        }

        int left = 0;
        for (int i = 0; i < n; i++) {
            ll right_b = arr[i];
            ll left_b = right_b - m;
            while (left < n && arr[left] < left_b) left++;

            ll sum = left_b * left - get_sub_sum(0, left);
            sum += get_sub_sum(i, n) - right_b * (n - i);

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
