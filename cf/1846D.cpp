// https://codeforces.com/problemset/problem/1846/D
#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using lli = long long int;



double eval() {
    vector<lli> base;
    lli n, d, h;
    double res = 0.0, cur_h, cur_tip;
    cin >> n >> d >> h;
    copy_n(istream_iterator<lli>(cin), n, back_inserter(base));
    for (int i = 0; i < n - 1; i++) {
        lli diff = base[i+1] - base[i];
        cur_h = h;
        cur_tip = 0;
        if (diff < h) {
            cur_tip = (1.0 - diff / cur_h) * d;
            cur_h = diff;
        }

        res += (cur_tip + d) * cur_h / 2.0;
    }
    res += (d * h) / 2.0;
    return res;
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << setprecision(7) << fixed << eval() << endl;
    
    return 0;
}

