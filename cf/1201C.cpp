// https://codeforces.com/contest/1201/problem/C
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> nums;
    ll n, k;

    cin >> n >> k;
    copy_n(istream_iterator<ll>(cin), n, back_inserter(nums));
    sort(all(nums));
    
    ll m_i = n / 2, cnt = 1;
    while (m_i + 1 < n && k >= (nums[m_i + 1] - nums[m_i]) * cnt) {
        k -= (nums[m_i + 1] - nums[m_i]) * cnt;
        m_i++; cnt++;
    }
    cout << nums[m_i] + k / cnt << endl;
    

    return 0;
}

