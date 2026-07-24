// https://codeforces.com/contest/295/problem/A
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


using lli = long long int;
struct query {
    lli i, j, d;

    friend istream &operator>>(istream &is, query &q) {
        return is >> q.i >> q.j >> q.d;
    }
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<lli> nums(n+2);
    vector<query> intervals(m+2);
    vector<lli> iprefix(m+2), nprefix(n+2);

    copy_n(istream_iterator<lli>(cin), n, begin(nums)+1);
    copy_n(istream_iterator<query>(cin), m, begin(intervals)+1);

    int a, b;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        iprefix[a]++;
        iprefix[b+1]--;
    }

    lli apply = 0;
    for (int i = 1; i <= m; i++) {
        apply += iprefix[i];
        auto [b, e, d] = intervals[i];
        nprefix[b] += d * apply;
        nprefix[e+1] -= d * apply;
    }

    apply = 0;
    for (int i = 1; i <= n; i++) {
        apply += nprefix[i];
        nums[i] += apply;
    }

    copy(begin(nums)+1, end(nums)-1, ostream_iterator<lli>(cout, " "));
    return 0;
}




