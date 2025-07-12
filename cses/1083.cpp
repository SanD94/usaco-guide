// https://cses.fi/problemset/task/1083
#include<iostream>
using namespace std;

typedef long long int lli;
int main() {
    lli n, k;
    cin >> n;
    lli res = n * (n + 1) / 2;
    for (int i = 1; i < n; i++) {
        cin >> k;
        res -= k;
    }
    cout << res << endl;
}