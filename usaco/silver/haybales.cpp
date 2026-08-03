// https://codeforces.com/contest/1744/problem/F
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set_io("haybales");
    int n, q;
    cin >> n >> q;
    vector<int> bales(n);

    copy_n(istream_iterator<int>(cin), n, begin(bales));
    sort(all(bales));

    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        auto l = lower_bound(all(bales), a);
        auto r = upper_bound(all(bales), b);
        cout << r - l << endl;
    }

    return 0;
}

