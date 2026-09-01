// https://codeforces.com/contest/1520/problem/F1
#include <iostream>
using namespace std;


int main() {
    int n, t, k;
    cin >> n >> t >> k;
    int l = 1, r = n, cur_sum;

    while (l < r) {
        int m = l + (r - l) / 2;
        cout << "? " << l << " " << m << endl;
        cin >> cur_sum;

        int cur_k = (m - l) + 1 - cur_sum;
        if (cur_k >= k) r = m;
        else {
            k -= cur_k;
            l = m + 1;
        }
    }

    cout << "! " << l << endl;
    return 0;
}


