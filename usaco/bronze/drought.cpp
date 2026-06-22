// https://usaco.org/index.php?page=viewproblem2&cpid=1181
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using lli = long long int;

lli eval() {
    int n, mn = 1e9, diff = 0;
    lli res = 0;
    vector<int> cows;
    cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(cows));

    if (n == 1) return 0;
    if (n == 2 && cows[0] != cows[1]) return -1;
    
    for (int i = 0; i < n; i += 2) {
        if (i + 1 == n) break;
        cows[i] -= diff;
        if (cows[i] < 0) return -1;

        mn = min(cows[i], mn);
        diff = cows[i+1] - cows[i];

        if (diff < 0) return -1;

        res += 2 * diff;
        cows[i+1] = cows[i];
    }

    if (n % 2) {
        cows[n-1] -= diff;
        if (cows[n-1] > cows[n-2] || cows[n-1] < 0) return -1;
        mn = min(cows[n-1], mn);
    }

    for (auto &c : cows) res += c - mn;
    
    return res;
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << eval() << endl;
    
    return 0;
}

