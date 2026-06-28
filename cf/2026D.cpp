// https://codeforces.com/contest/2026/problem/D
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using lli = long long int;

vector<int> nums;
vector<lli> prefix, pprefix, ppprefix;
vector<lli> idx_list;
int n, t;
lli a, b;

pair<lli, lli> get_indices(lli idx) {
    auto lower = lower_bound(begin(idx_list), end(idx_list), idx);
    lli index = distance(begin(idx_list), lower);
    return {index - 1, idx - idx_list[index - 1] + index - 2};
}


void preprocess() {
    prefix.assign(n + 1, 0);
    pprefix.assign(n + 1, 0);
    ppprefix.assign(n + 1, 0);
    for(int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + nums[i];
        pprefix[i+1] = pprefix[i] + prefix[i+1];
    }
    for(int i = 0; i < n; i++)
        ppprefix[i+1] = pprefix[n] - pprefix[i] - (n - i) * prefix[i] + ppprefix[i];



    idx_list.push_back(0);
    for(int i = n; i > 0; i--)
        idx_list.push_back(idx_list.back() + i);
}

lli get_sum(int row, int l, int r) {
    if (l >= r) return 0;
    return pprefix[r] - pprefix[l] - prefix[row] * (r - l);
}

lli eval(lli a, lli b) {
    auto [ai, aj] = get_indices(a);
    auto [bi, bj] = get_indices(b);


    lli res = ppprefix[bi + 1] - ppprefix[ai];
    lli left = get_sum(ai, ai, aj);
    lli right = get_sum(bi, bj + 1, n);

    return res - left - right;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(nums));
    preprocess();
    cin >> t;
    while (t--) {
        cin >> a >> b;
        cout << eval(a, b) << endl;
    }


    return 0;
}
