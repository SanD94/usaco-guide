// https://usaco.org/index.php?page=viewproblem2&cpid=572
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

vector<vector<int>> eval(vector<int> &cows) {
    vector<vector<int>> res(3, vector<int>(cows.size() + 1));
    for (size_t i = 0; i < cows.size(); i++) 
        for (size_t j = 1; j <= 3; j++)
            res[j-1][i+1] = res[j-1][i] + (j == cows[i]);
    
    return res;
}

int main() {
    set_io("bcount");
    int n, q;
    cin >> n >> q;
    vector<int> cows;

    copy_n(istream_iterator<int>(cin), n, back_inserter(cows));
    vector<vector<int>> cnt_cows = eval(cows);

    int a, b;
    while(q--) {
        cin >> a >> b;
        int h = cnt_cows[0][b] - cnt_cows[0][a-1];
        int g = cnt_cows[1][b] - cnt_cows[1][a-1];
        int j = cnt_cows[2][b] - cnt_cows[2][a-1];

        cout << h << " " << g << " " << j << endl;
    }

    return 0;
}

