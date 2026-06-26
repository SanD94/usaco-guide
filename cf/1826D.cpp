// https://codeforces.com/contest/1826/problem/D
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using lli = long long int;
const int NEG = -1e9;

int eval() {
    int n;
    cin >> n;
    vector<int> vals(n), prefix(n+1, NEG), suffix(n+1, NEG);
    copy_n(istream_iterator<int>(cin), n, begin(vals));
    
    for (int i = 0; i < n; i++)
        prefix[i+1] = max(vals[i] + i, prefix[i]);
    for (int i = n-1; i >= 0; i--)
        suffix[i] = max(vals[i] - i, suffix[i + 1]);

    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(prefix[i] + vals[i] + suffix[i + 1], res);

    return res;
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << eval() << endl;
    
    return 0;
}
