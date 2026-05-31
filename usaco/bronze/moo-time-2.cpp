// https://usaco.org/index.php?page=viewproblem2&cpid=1468
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

typedef long long int lli;

int N;
vector<int> moo;
vector<bool> self_ignored;
vector<int> cnt, last_pair_used;
lli pair_cnt, res;

void eval() {
    cnt.resize(N+1);
    last_pair_used.resize(N+1);
    self_ignored.resize(N+1);

    for (auto it = moo.rbegin(); it != moo.rend(); it ++) {
        int n = *it;
        cnt[n]++;
        res += pair_cnt - last_pair_used[n];
        last_pair_used[n] = pair_cnt;
        if (cnt[n] == 2) pair_cnt++;
        if (!self_ignored[n] && cnt[n] > 2) {
            res --;
            self_ignored[n] = true;
        } 
    }
}

int main(int argc, char const *argv[]) {
    cin >> N;
    copy_n(istream_iterator<int>(cin), N, back_inserter(moo));
    eval();
    cout << res << endl;
    return 0;
}

