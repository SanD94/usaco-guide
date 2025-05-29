// https://cses.fi/problemset/task/1068
#include<iostream>
using namespace std;

typedef long long int lli;
int main() {
    lli n;
    cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n % 2) n = 3*n + 1;
        else n >>= 1;
    }
    cout << 1 << endl;
    return 0;
}