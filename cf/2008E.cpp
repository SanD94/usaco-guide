// https://codeforces.com/contest/2008/problem/E
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

using lli = long long int;

vector<vector<int>> eval_pos(string s) {
    vector<vector<int>> res(s.size() + 1, vector<int>(26));
    for (int i = 0; i < s.size(); i++) {
        int idx = s[i] - 'a';
        for (int j = 0; j < 26; j++)
            res[i+1][j] = res[i][j] + (idx == j);
    }
    return res;
}


int remove_one(string s, vector<vector<int>> &even_pos, vector<vector<int>> &odd_pos) {
    int res = s.size();
    int even_size = s.size() / 2 + 1, odd_size = s.size() / 2;
    for (int i = 0; i < s.size(); i++) {
        int res_even_mx = 0, res_odd_mx = 0;
        if (i % 2) {
            for (int j = 0; j < 26; j++) {
                res_odd_mx = max(res_odd_mx, odd_pos[i/2][j] + even_pos[even_size][j] - even_pos[i/2+1][j]);
                res_even_mx = max(res_even_mx, even_pos[i/2+1][j] + odd_pos[odd_size][j] - odd_pos[i/2+1][j]);
            }
        } else {
            for (int j = 0; j < 26; j++) {
                res_odd_mx = max(res_odd_mx, odd_pos[i/2][j] + even_pos[even_size][j] - even_pos[i/2+1][j]);
                res_even_mx = max(res_even_mx, even_pos[i/2][j] + odd_pos[odd_size][j] - odd_pos[i/2][j]);
            }
        }


        res = min(res, (int)s.size() - res_even_mx - res_odd_mx);
    }
    return res;
}

int eval() {
    int n;
    string s;
    cin >> n >> s;
    string s_even(""), s_odd("");
    for (int i = 1; i < s.size(); i+=2)
        s_odd += s[i];
    for (int i = 0; i < s.size(); i+=2)
        s_even += s[i];


    vector<vector<int>> even_pos = eval_pos(s_even);
    vector<vector<int>> odd_pos = eval_pos(s_odd);

    int res_even_mx = 0, res_odd_mx = 0;

    if (s.size() % 2) return remove_one(s, even_pos, odd_pos);

    for (int i = 0; i < 26; i++) res_even_mx = max(res_even_mx, even_pos[s_even.size()][i]);
    for (int i = 0; i < 26; i++) res_odd_mx = max(res_odd_mx, odd_pos[s_odd.size()][i]);


    return s.size() - res_even_mx - res_odd_mx;
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << eval() << endl;
    
    return 0;
}






