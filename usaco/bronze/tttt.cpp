// https://usaco.org/index.php?page=viewproblem2&cpid=831
#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
    set_io("tttt");
    array<string, 3> ttt;
    copy(istream_iterator<string>(cin), istream_iterator<string>(), ttt.begin());
    
    // single claim
    array<bool, 26> single{};
    for (int i = 0; i < 26; i++) {
        char ch = 'A' + i;
        // row 
        for (int j = 0; j < 3; j++) {
            bool ok = true;
            for (int k = 0; k < 3; k++) if (ttt[j][k] != ch) ok = false;
            if (ok) single[i] = true;
        }
        // column
        for (int j = 0; j < 3; j++) {
            bool ok = true;
            for (int k = 0; k < 3; k++) if (ttt[k][j] != ch) ok = false;
            if (ok) single[i] = true;
        }
        // diagonal
        bool ok = true;
        for (int j = 0; j < 3; j++) {
            if (ttt[j][j] != ch) ok = false;
        }
        if (ok) single[i] = true;
        for (int j = 0; j < 3; j++) {
            if (ttt[j][3-j] != ch) ok = false;
        }
        if (ok) single[i] = true;
    }
    int res = accumulate(single.begin(), single.end(), 0, plus<int>());
    cout << res << endl;

    // team claim
    array<array<bool, 26>, 26> team{};
    for (int i = 0; i < 26; i++)
        for(int j = i + 1; j < 26; j++) {
            if (i == j) continue;
            char ch1 = i + 'A', ch2 = j + 'A';
            
            // row
            for (int k = 0; k < 3; k++) {
                int cnt1 = 2, cnt2 = 2;
                for (int l = 0; l < 3; l++)  {
                    if (ttt[k][l] == ch1) cnt1 --;
                    if (ttt[k][l] == ch2) cnt2 --;
                }
                if (cnt1 >= 0 && cnt2 >= 0 && cnt1 + cnt2 == 1)
                    team[i][j] = true;
            }
            // column
            for (int k = 0; k < 3; k++) {
                int cnt1 = 2, cnt2 = 2;
                for (int l = 0; l < 3; l++)  {
                    if (ttt[l][k] == ch1) cnt1 --;
                    if (ttt[l][k] == ch2) cnt2 --;
                }
                if (cnt1 >= 0 && cnt2 >= 0 && cnt1 + cnt2 == 1)
                    team[i][j] = true;
            }
            // diag
            int cnt1 = 2, cnt2 = 2;
            for (int k = 0; k < 3; k++) {
                if (ttt[k][k] == ch1) cnt1--;
                if (ttt[k][k] == ch2) cnt2--;
            }
            if (cnt1 >= 0 && cnt2 >= 0 && cnt1 + cnt2 == 1)
                team[i][j] = true;
            cnt1 = 2, cnt2 = 2;
            for (int k = 0; k < 3; k++) {
                if (ttt[k][k] == ch1) cnt1--;
                if (ttt[k][k] == ch2) cnt2--;
            }
            if (cnt1 >= 0 && cnt2 >= 0 && cnt1 + cnt2 == 1)
                team[i][j] = true;
            cnt1 = 2, cnt2 = 2;
            for (int k = 0; k < 3; k++) {
                if (ttt[k][3-k] == ch1) cnt1--;
                if (ttt[k][3-k] == ch2) cnt2--;
            }
            if (cnt1 >= 0 && cnt2 >= 0 && cnt1 + cnt2 == 1)
                team[i][j] = true;
        }
    res = 0;
    for(auto &arr : team) for (auto &elem: arr) if (elem) res++;
    cout << res << endl;

    return 0;
}
