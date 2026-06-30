// https://usaco.org/index.php?page=viewproblem2&cpid=416
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int n, step;
vector<vector<int>> grass;
vector<vector<int>> pref;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

// sum = i + j
// diff = i - j + (n - 1) --> shift
// (r, c) center
// abs(i - r) + abs(j - c) <= step
// abs((i + j) - (r + c)) <= step -> both same sign
// abs((i - j) - (r - c)) <= step -> opposite signs
// center - step <= sum <= center + step
// center - step <= diff <= center + step
void preprocess() {
    int m = 2*n - 1;
    pref.assign(m + 1, vector<int>(m + 1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sm = i + j;
            int diff = i - j + n - 1;
            pref[sm + 1][diff + 1] = grass[i][j];
        }
    }

    for (int sm = 0; sm < m; sm++) {
        for (int diff = 0; diff < m; diff++) {
            pref[sm + 1][diff + 1] += pref[sm][diff + 1]
                + pref[sm + 1][diff]
                - pref[sm][diff];
        }
    }
}


int eval() {
    int res = 0;
    int m = 2*n - 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sm = i + j;
            int diff = i - j + n - 1;

            int sm1 = max(0, sm - step);
            int sm2 = min(m - 1, sm + step);
            int diff1 = max(0, diff - step);
            int diff2 = min(m - 1, diff + step);

            int cur = pref[sm2 + 1][diff2 + 1]
                - pref[sm1][diff2 + 1]
                - pref[sm2 + 1][diff1]
                + pref[sm1][diff1];
            res = max(res, cur);
        }
    }
    return res;
}




int main() {
    set_io("lazy");
    cin >> n >> step;

    grass.assign(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        copy_n(istream_iterator<int>(cin), n, begin(grass[i]));
    preprocess();

    cout << eval() << endl;
    return 0;
}

