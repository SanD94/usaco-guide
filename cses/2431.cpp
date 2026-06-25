// https://cses.fi/problemset/task/2431/
#include <iostream>
#include <cmath>
using namespace std;

using lli = long long int;

int eval() {
    lli q, lim = 9, digit = 1;
    cin >> q;
    while (q > digit * lim) {
        q -= digit * lim;
        lim *= 10;
        digit++;
    }

    lli beg = pow(10, digit-1);
    lli num = beg + (q - 1) / digit;
    lli rem = (digit - (q % digit)) % digit;
    while(rem --) num /= 10;
    return num % 10;
}

int main() {
    int t;
    cin >> t;
    while (t--) cout << eval() << endl;
}




