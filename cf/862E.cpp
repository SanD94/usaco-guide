// https://codeforces.com/contest/862/problem/E
#include <iostream>
#include <iterator>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#define all(x) begin(x),end(x)
using ll = long long;

ll eval(ll x, vector<ll>& arr) {
    int sz = (int) arr.size() - 1;
    int l = -1, r = sz;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        if (x < arr[m]) r = m - 1;
        else l = m;
    }
    if (l == -1) return abs(x - arr[0]);
    if (l == sz) return abs(x - arr.back());
    return min(abs(x - arr[l]), abs(x - arr[l+1]));
}

int main() {
    int n, m, q;
    
    cin >> n >> m >> q;
    vector<ll> a, b;
    ll fa = 0;
    vector<ll> fb(m - n + 1, 0);
    vector<ll> dir{1, -1};

    copy_n(istream_iterator<ll>(cin), n, back_inserter(a));
    copy_n(istream_iterator<ll>(cin), m, back_inserter(b));

    for (int i = 0; i < n; i++) 
        fa += a[i] * dir[i % 2];
    for (int i = 0; i < n; i++) 
        fb[0] += b[i] * dir[i % 2];
    for (int i = n, j = 0; i < m; i++, j++) 
        fb[j+1] = -fb[j] + b[j] + b[i] * dir[(n+1) % 2];

    sort(all(fb));


    cout << eval(fa, fb) << endl;

    
    int l, r, x;
    while (q--) {
        cin >> l >> r >> x;
        l--; r--;
        if ((r - l) % 2 == 0)
            fa += x * dir[l % 2];
        
        cout << eval(fa, fb) << endl;
    }
    return 0;
}



