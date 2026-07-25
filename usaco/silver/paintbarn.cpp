// https://usaco.org/index.php?page=viewproblem2&cpid=919
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1000;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    set_io("paintbarn");
    int n, k;
    cin >> n >> k;
    vector<vector<int>> diff(MAXN + 2, vector<int>(MAXN + 2));

    int a, b, c, d;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        diff[a][b]++;
        diff[a][d]--;
        diff[c][b]--;
        diff[c][d]++;
    }

    int cnt = 0;
    for (int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++) {
            int up = (i - 1 >= 0 ? diff[i-1][j] : 0);
            int left = (j - 1 >= 0 ? diff[i][j-1] : 0);
            int upleft = ((i - 1 >= 0 && j - 1 >= 0) ? diff[i-1][j-1] : 0);
            diff[i][j] += up + left - upleft;
            if (diff[i][j] == k) cnt++;
        }

    cout << cnt << endl;
    return 0;
}

