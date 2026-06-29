// https://codeforces.com/gym/104114/problem/N
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using lli = long long int;

int main() {
    int n, m;
    cin >> n >> m;
    vector<lli> salts;
    vector<lli> lmax(n+1, 0);
    vector<lli> rmax(n+1, 0);
    copy_n(istream_iterator<lli>(cin), n, back_inserter(salts));

    for (int i = 0; i < n; i++) 
        lmax[i+1] = max(lmax[i] - m, salts[i]);
    for (int i = n - 1; i >= 0; i--)
        rmax[i] = max(rmax[i + 1] - m, salts[i]);

    for (int i = 0; i < n; i++) {
        lli num = max(
            rmax[i],
            lmax[i+1]
        );
        cout << num << " ";
    }

    return 0;
}

