// https://cses.fi/problemset/task/1652
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;


vector<string> forest;
vector<vector<int>> cnt;
int n, t;

void read() {
    cin >> n >> t;
    copy_n(istream_iterator<string>(cin), n, back_inserter(forest));
    cnt.assign(n+1, vector<int>(n+1));
}

void preprocess() {
    for (int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cnt[i+1][j+1] = cnt[i][j+1] + cnt[i+1][j] - cnt[i][j] + (forest[i][j] == '*');
}

int eval() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--; b--;
    return cnt[c][d] - cnt[c][b] - cnt[a][d] + cnt[a][b];
}



int main() {
    read();
    preprocess();
    while(t--) cout << eval() << endl;

    return 0;
}

