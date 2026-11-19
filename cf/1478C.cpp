// https://codeforces.com/problemset/problem/1478/C
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;


bool eval(vector<ll>& elems, int n) {
    sort(all(elems));
    if (elems[0] != elems[1]) return false;

    ll sum = elems[0];
    if (sum % 2 == 1) return false;

    sum >>= 1;

    ll running_diff = 0, running_sum = 0;
    for (int i = 1; i < n; i++) {
        if (elems[2*i] == elems[2*i-2]) return false;
        if (elems[2*i] != elems[2*i+1]) return false;
        if (elems[2*i] % 2 == 1) return false;

        ll diff = elems[2*i] - elems[2*i-2];
        if (diff % (2 * i) != 0) return false;

        running_diff += diff / (2 * i);
        running_sum += running_diff;
    }


    if (running_sum >= sum || (sum - running_sum) % n != 0) return false;

    return true;
}


int main() {
    int t;
    cin >> t;
    while(t --) {
        int n;
        vector<ll> diffs;

        cin >> n;
        copy_n(istream_iterator<ll>(cin), 2*n, back_inserter(diffs));

        cout << (eval(diffs, n) ? "YES" : "NO") << endl;
    }

    return 0;
}



