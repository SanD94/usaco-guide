// https://codeforces.com/contest/1291/problem/D
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

string s;
vector<vector<int>> prefix;

void preprocess() {
    prefix.assign(s.length() + 1, vector<int>(26));
    for (int i = 0; i < s.length(); i++)
        for (int j = 0; j < 26; j++)
            prefix[i+1][j] = prefix[i][j] + (j == s[i] - 'a');
}


// Reducible iff some proper prefix p has same count vector in S and anagram T:
// equal prefix gives a split; first reducible block gives such prefix.
// Need an anagram whose prefix vectors never meet.
// a) |S|=1: no split. 
// b) S[0]!=S[n-1]: swap ends; every prefix has +last-first.
// c) >=3 chars: for x..y..z..x, put z..x..x..y; diffs are +z-x,+z-y,+x-y.
// Else <=2 chars with equal ends. Count only non-end char: any T starts/ends
// with end char (instant match) or starts/ends with other char (diff crosses 0).
string eval(int l, int r) {
    int distinct = 0;
    for (int i = 0; i < 26; i++)
        if (prefix[r][i] - prefix[l][i] > 0) distinct++;
    if (r - l == 1 || s[r-1] != s[l]  || distinct >= 3)
        return "Yes";
    return "No";
}


int main() {
    int t, a, b;
    cin >> s >> t;
    preprocess();
    while (t--) {
        cin >> a >> b;
        cout << eval(a-1, b) << endl;
    }
    
    return 0;
}

