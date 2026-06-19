// https://codeforces.com/problemset/problem/1772/D
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using lli = long long int;



int eval() {
    int n;
    vector<int> vals;
    cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(vals));
    int mn = 0, mx = 1e9;
    for (int i = 0; i < n - 1; i++) {
        int a = vals[i], b = vals[i+1];
        if (a == b) continue;
        if (a < b) mx = min(mx, (a+b)/2);
        if (b < a) mn = max(mn, (a+b+1)/2);
    }
    if (mn > mx) return -1;
    return mn;
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << eval() << endl;
    
    return 0;
}



