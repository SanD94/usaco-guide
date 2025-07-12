// https://cses.fi/problemset/task/1070
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (1 < n && n < 4) {
        cout << "NO SOLUTION" << endl;
        return 0;
    }

    for (int i = 2; i <= n; i += 2) cout << i << " ";
    cout << 1;
    for (int i = 3; i <= n; i += 2) cout << " " << i;
    cout << endl;
    return 0;
}