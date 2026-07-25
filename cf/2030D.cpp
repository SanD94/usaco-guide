// https://codeforces.com/contest/2030/problem/D
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void eval() {
    int n, q;
    cin >> n >> q;

    vector<int> perm(n+1);
    vector<bool> is_good(n+1), boundary(n+1);
    string s;

    copy_n(istream_iterator<int>(cin), n, begin(perm)+1);
    cin >> s;

    int diff = 0, bad_cnt = 0;
    for (int i = 1; i <= n; i++) {
        diff += perm[i] - i;
        is_good[i] = !diff;
        boundary[i] = (s[i-1] == 'L' && s[i] == 'R');
        bad_cnt += !is_good[i] && boundary[i];
    }

    int a;
    while(q--) {
        cin >> a;
        s[a-1] = (s[a-1] == 'L' ? 'R' : 'L');
        if (!is_good[a] && boundary[a]) bad_cnt--;
        if (!is_good[a-1] && boundary[a-1]) bad_cnt--;

        boundary[a] = (s[a-1] == 'L' && s[a] == 'R');
        boundary[a-1] = (s[a-2] == 'L' && s[a-1] == 'R');

        if (!is_good[a] && boundary[a]) bad_cnt++;
        if (!is_good[a-1] && boundary[a-1]) bad_cnt++;

        cout << (!bad_cnt ? "YES" : "NO") << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t--)
        eval();

    return 0;
}





