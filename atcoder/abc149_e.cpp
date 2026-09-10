// https://atcoder.jp/contests/abc149/tasks/abc149_e
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <tuple>
using namespace std;

using ll = long long;

#define all(x) begin(x),end(x)

vector<ll> preprocess(vector<ll>& arr) {
    vector<ll> res(arr.size() + 1);
    for (size_t i = 0; i < arr.size(); i++)
        res[i+1] = res[i] + arr[i];
    return res;
}

ll cnt_large(vector<ll>& arr, ll x) {
    ll l = 0, r = (ll)arr.size();
    while (l < r) {
        ll m = l + (r - l) / 2;
        if (arr[m] < x) r = m;
        else l = m + 1;
    }
    return l;
}

tuple<ll, ll> eval(vector<ll>& arr, vector<ll>&p, ll x) {
    ll res = 0, cnt_res = 0;
    for (auto& a : arr) {
        ll cnt = cnt_large(arr, x - a);
        cnt_res += cnt;
        res += p[cnt] + 1LL * cnt * a;
    }
    return { cnt_res, res };
}


int main() {
    ll n;
    ll m;
    vector<ll> power;

    cin >> n >> m;
    copy_n(istream_iterator<ll>(cin), n, back_inserter(power));

    sort(all(power), [](const ll lhs, const ll rhs) {
        return rhs < lhs;
    });
    vector<ll> prefix = preprocess(power);


    ll l = 0, r = 2 * power[0];
    while (l < r) {
        ll mid = l + (r - l + 1) / 2;
        auto [cnt, _] = eval(power, prefix, mid);
        if (cnt < m) r = mid - 1;
        else l = mid;
    }

    auto [cnt, sum] = eval(power, prefix, l);
    ll res = sum - (cnt - m) * l;

    cout << res << endl;

    return 0;
}
