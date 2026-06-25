// https://cses.fi/problemset/task/1661
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
using namespace std;

using lli = long long int;

lli eval() {
    int n;
    lli res = 0, x;
    cin >> n >> x;


    vector<lli> sum(n+1), s(n);
    map<lli, lli> cnt;

    copy_n(istream_iterator<int>(cin), n, begin(s));

    for (int i = 0; i < n; i++)
        sum[i+1] = sum[i] + s[i];
    
    for (int i = 0; i <= n; i++) {
        res += cnt[sum[i]-x];
        cnt[sum[i]]++;
    }

    return res;
}


int main() {
    cout << eval() << endl;
    return 0;
}
