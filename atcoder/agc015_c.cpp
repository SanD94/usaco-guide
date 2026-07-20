// https://atcoder.jp/contests/agc015/tasks/agc015_c
#include <iostream>
#include <vector>
using namespace std;

using lli = long long int;

int n, m, q;
vector<vector<bool>> mark;
vector<vector<int>> horizontal, vertical, cnt;

void read() {
    string s;
    cin >> n >> m >> q;
    mark.assign(n, vector<bool>(m));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            mark[i][j] = s[j] - '0';
    }
}

void preprocess() {
    horizontal.assign(n+1, vector<int>(m+1));
    vertical.assign(n+1, vector<int>(m+1));
    cnt.assign(n+1, vector<int>(m+1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cnt[i][j] = cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1] + mark[i-1][j-1];
            horizontal[i][j] = horizontal[i][j-1] + horizontal[i-1][j] - horizontal[i-1][j-1] + (j - 2 >= 0 && mark[i-1][j-2] && mark[i-1][j-1]);
            vertical[i][j] = vertical[i-1][j] + vertical[i][j-1] - vertical[i-1][j-1] + (i - 2 >= 0 && mark[i-2][j-1] && mark[i-1][j-1]);
        }
}

int pcalc(vector<vector<int>> &vec, int a, int b, int c, int d) {
    return vec[c][d] - vec[c][b] - vec[a][d] + vec[a][b];
}


void eval() {
    int a, b, c, d;
    while (q--) {
        cin >> a >> b >> c >> d;
        a--; b--;
        int cnt_q = pcalc(cnt, a, b, c, d);
        int cnt_hor = pcalc(horizontal, a, b+1, c, d);
        int cnt_ver = pcalc(vertical, a+1, b, c, d);
        cout << cnt_q - cnt_hor - cnt_ver << endl;
    }
}

int main() {
    read();
    preprocess();
    eval();

    return 0;
}

