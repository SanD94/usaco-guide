// https://cses.fi/problemset/task/3399
#include <iostream>
using namespace std;


void eval() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == 0 && b == 0) {
        cout << "YES" << endl;
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++)
                cout << j << " ";
            cout << endl;
        }
        return;
    }
    
    if (a >= 1 && b >= 1 && a + b <= n) {
        int k = n - (a + b);
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << endl;
        for (int i = 1; i <= k; i++)
            cout << i << " ";
        for (int i = 0; i < b; i++)
            cout << (k + 1 + a + i) << " ";
        for (int i = 0; i < a; i++)
            cout << (k + 1 + i) << " ";
        cout << endl;
        return;
    }

    cout << "NO" << endl;
}


int main() {
    int t;
    cin >> t;
    while (t--)
        eval();
    
    return 0;
}
