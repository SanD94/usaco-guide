// https://cses.fi/problemset/task/1071
#include<iostream>
#include<cmath>
using namespace std;

typedef long long int lli;
int main(int argc, char const *argv[]) {
    lli t, x, y, n;
    cin >> t;
    while (t--) {
        cin >> y >> x;
        n = max(y, x);

        if (n % 2) swap(y, x);
        
        lli np = n * n;

        cout << np - (n - y) - (x - 1) << endl;
    }
    return 0;
}
