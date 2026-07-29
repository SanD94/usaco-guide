// https://usaco.org/index.php?page=viewproblem2&cpid=643
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set_io("diamond");

    int n, k;
    vector<int> diamonds;
    cin >> n >> k;
    copy_n(istream_iterator<int>(cin), n, back_inserter(diamonds));
    vector<int> left(n+1), right(n+1);

    sort(begin(diamonds), end(diamonds));

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int elem = diamonds[i-1];
        while (abs(diamonds[idx] - elem) > k) idx++;
        left[i] = max(left[i-1], i - idx);
    }
    idx = n;
    for (int i = n - 1; i >= 0; i--) {
        int elem = diamonds[i];
        while(abs(diamonds[idx - 1] - elem) > k) idx--;
        right[i] = max(right[i+1], idx - i);
    }

    int res = 0;
    for (int i = 0; i <= n; i++) res = max(res, left[i] + right[i]);

    cout << res << endl;
    return 0;
}


