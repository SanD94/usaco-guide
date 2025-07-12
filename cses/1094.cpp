// https://cses.fi/problemset/task/1094
#include<iostream>
#include<cmath>
using namespace std;

typedef long long int lli;

int main() {
    int n;
    lli x, mn = 0, res = 0;
    cin >> n;


    cin >> x;
    mn = x;
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x < mn) res += mn - x;
        mn = max(mn, x);
    }
    cout << res << endl;
    return 0;
}
