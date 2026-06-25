// https://codeforces.com/contest/1398/problem/C
#include <iostream>
#include <vector>
#include <map>
using namespace std;

using lli = long long int;

lli eval() {
    int n;
    string s;
    lli res = 0;
    cin >> n >> s;
    vector<int> sum(n+1);
    map<int, int> cnt;

    for (int i = 0; i < n; i++) sum[i+1] = sum[i] + s[i] - '0';
    for (int i = 0; i <= n; i++) cnt[sum[i] - i]++;
    for (const auto &[_, v] : cnt) {
        lli vv = v;
        res += vv * (vv - 1) / 2;
    }
    return res;
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << eval() << endl;
    
    return 0;
}





