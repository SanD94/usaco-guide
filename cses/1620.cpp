// https://cses.fi/problemset/task/1620
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


using ll = unsigned long long;
const ll MX = 1e18 + 10;


bool can_produce(vector<int>& machines, ll t, ll p) {
    ll cur_p = 0;
    for (auto& m: machines) {
        cur_p += t / m;
        if (cur_p >= p) return true;
    }
    return false;
}


int main() {
    int n;
    ll t;
    vector<int> machines;
    
    cin >> n >> t;
    copy_n(istream_iterator<int>(cin), n, back_inserter(machines));

    ll l = 0, r = MX;
    while (l < r) {
        ll m = l + (r - l) / 2;
        if (can_produce(machines, m, t)) r = m;
        else l = m + 1;
    }

    cout << l << endl;
    return 0;
}

