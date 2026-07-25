// https://codeforces.com/contest/276/problem/C
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

using lli = long long int;



int main() {
    int n, q;
    cin >> n >> q;
    
    vector<lli> nums, diff(n+2), cnt(n+2);

    copy_n(istream_iterator<lli>(cin), n, back_inserter(nums));
    int a, b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        diff[a]++;
        diff[b+1]--;
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur += diff[i];
        cnt[i] = cur;
    }

    lli res = 0;
    sort(begin(nums), end(nums));
    sort(begin(cnt)+1, end(cnt)-1);

    for(int i = 0; i < n; i++) res += cnt[i+1] * nums[i];
    cout << res << endl;

    return 0;
}





