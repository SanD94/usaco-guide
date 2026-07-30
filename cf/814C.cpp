// https://codeforces.com/problemset/problem/814/C
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    string s;
    int m;
    char c;

    cin >> n >> s >> q;
    while (q --) {
        cin >> m >> c;
        int r = 0, res = 0;
        for (int l = 0; l < n; l++) {
            while(r < n && (m || s[r] == c)) {
                if (s[r] != c) m--;
                r++;
            }
            res = max(res, r - l);
            m += s[l] != c;
        }
        cout << res << endl;
    }


    return 0;
}




