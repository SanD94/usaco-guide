// https://cses.fi/problemset/task/1072
#include<iostream>
#include<cmath>
using namespace std;

typedef long long int lli;

lli eval(lli n) {
    if (n == 1) return 0;
    if (n == 2) return 6;
    if (n == 3) return 28;
    lli res = (n - 1)*(n*n*(n+1)/2 - 4*(n-2));
    return res;
}


int main(int argc, char const *argv[]) {
    lli n;
    cin >> n;
    for (lli i = 1; i <= n; i++) {
        cout << eval(i) << endl;
    }
    return 0;
}
