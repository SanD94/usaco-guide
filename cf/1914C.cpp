// https://codeforces.com/problemset/problem/1914/C
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using lli = long long int;



lli eval() {
    int n, k;
    vector<lli> a, b;
    cin >> n >> k;
    copy_n(istream_iterator<lli>(cin), n, back_inserter(a));
    copy_n(istream_iterator<lli>(cin), n, back_inserter(b));
    lli res = 0, cur_res = 0;
    lli cur_mx = 0;
    for (int i = 0; i < min(n, k); i++) {
        cur_res += a[i]; 
        cur_mx = max(cur_mx, b[i]);
        res = max(res, cur_res + (k - i - 1) * cur_mx);
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


