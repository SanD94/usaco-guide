// https://cses.fi/problemset/task/1662
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

using lli = long long int;

lli eval() {
    int n;
    lli res = 0;
    cin >> n;

    vector<lli> sum(n+1), s(n);
    vector<lli> cnt(n);

    copy_n(istream_iterator<int>(cin), n, begin(s));

    for (int i = 0; i < n; i++) {
        lli num = s[i];
        num = (num % n + n) % n;
        sum[i+1] = (sum[i] + num) % n;
    }
    for (int i = 0; i <= n; i++) cnt[sum[i]]++;
    for (const auto &v : cnt) {
        res += v * (v - 1) / 2;
    }
    return res;
}


int main() {
    cout << eval() << endl;
    return 0;
}






