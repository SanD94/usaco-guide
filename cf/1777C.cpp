// https://codeforces.com/contest/1777/problem/C
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

const int MAXM = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n, m;

    vector<vector<int>> factors(MAXM + 1);
    for (int i = 1; i <= MAXM; i++)
        for (int j = i; j <= MAXM; j += i)
            factors[j].push_back(i);


    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> arr;
        vector<int> f_cnt(m + 1);
        int res = MAXM, cur_target = 0;

        copy_n(istream_iterator<int>(cin), n, back_inserter(arr));
        sort(begin(arr), end(arr));

        auto l = arr.begin(), r = arr.begin();
        while (r != arr.end() || cur_target == m) {
            if (cur_target < m) {
                for (auto factor: factors[*r]) {
                    if (factor > m) break;
                    if (f_cnt[factor] == 0) cur_target++;
                    f_cnt[factor]++;
                }
                r++;
            }
            if (cur_target == m) {
                res = min(res, *(r - 1) - *l);
                for (auto factor: factors[*l]) {
                    if (factor > m) break;
                    f_cnt[factor]--;
                    if (f_cnt[factor] == 0) cur_target--;
                }
                l++;
            }
        }
        cout << (res == MAXM ? -1 : res) << endl;
    }

    return 0;
}

