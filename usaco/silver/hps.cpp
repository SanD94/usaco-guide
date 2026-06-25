// https://usaco.org/index.php?page=viewproblem2&cpid=691
#include <iostream>
#include <ostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int n;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int get_idx(char c) {
    string moves = "HSP";
    for(int i = 0; i < moves.size(); i++)
        if (moves[i] == c) return i;
    return -1;
}

bool is_winner(int m0, int m1) {
    return ((m0 + 1) % 3) == m1;
}

vector<vector<int>> get_winners(vector<int> &moves) {
    vector<vector<int>> res(3, vector<int>(n+1));
    for (int i = 0; i < moves.size(); i++)
        for(int j = 0; j < 3; j++)
            res[j][i+1] = res[j][i] + is_winner(j, moves[i]);

    return res;
}

int eval(vector<int> &moves) {
    vector<vector<int>> win_cnt = get_winners(moves);
    int res = 0;

    for (int k = 1; k <= n; k++) {
        int left = 0, right = 0;
        for (int i = 0; i < 3; i++) {
            left = max(left, win_cnt[i][k]);
            right = max(right, win_cnt[i][n] - win_cnt[i][k]);
            res = max(res, left + right);
        }
    }
        
    return res;
}


int main() {
    set_io("hps");

    char c;
    vector<int> moves;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> c;
        moves.push_back(get_idx(c));
    }

    cout << eval(moves) << endl;
    return 0;
}

