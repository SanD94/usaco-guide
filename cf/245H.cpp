// https://codeforces.com/contest/245/problem/H
#include <iostream>
#include <vector>
using namespace std;

using lli = long long int;

vector<vector<bool>> pal;
vector<vector<int>> dp;
string s;

void eval_pal(int n) {
    pal.assign(n+1, vector<bool>(n+1, false));
    for (int i = 0; i < n; i++)
        pal[i][i] = pal[i][i+1] = true;
    for (int len = 2; len <= n; len++) 
        for (int i = 0; i + len <= n; i++) {
            int l = i, r = i + len;
            pal[l][r] = pal[l+1][r-1] && s[l] == s[r-1];
        }
}

void eval_dp(int n) {
    dp.assign(n+1, vector<int>(n+1, 0));
    for (int len = 1; len <= n; len++)
        for (int i = 0; i + len <= n; i++) {
            int l = i, r = i + len;
            dp[l][r] = dp[l+1][r] + dp[l][r-1] - dp[l+1][r-1] + pal[l][r];
        }
}

void preprocess(int n) {
    eval_pal(n);
    eval_dp(n);
}

lli eval() {
    int a, b;
    cin >> a >> b;
    return dp[a-1][b];
}




int main() {
    int t;
    cin >> s >> t;
    preprocess(s.length());
    while (t--) cout << eval() << endl;

    return 0;
}

