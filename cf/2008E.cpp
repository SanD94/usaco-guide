// https://codeforces.com/contest/2008/problem/E
#include <iostream>
#include <vector>
using namespace std;

using lli = long long int;


int eval() {
    int n;
    string s;
    cin >> n >> s;

    vector<vector<int>> prefix(2, vector<int>(26)), suffix(2, vector<int>(26));
    int res = s.size();

    for (int i = 0; i < s.size(); i++)
        suffix[i%2][s[i]-'a']++;

    if (s.size() % 2 == 0) {
        int even_res = 0, odd_res = 0;
        for (int i = 0; i < 26; i++) {
            even_res = max(even_res, suffix[0][i]);
            odd_res = max(odd_res, suffix[1][i]);
        }
        res = s.size() - even_res - odd_res;
    } else {
        for (int i = 0; i < s.size(); i++) {
            suffix[i%2][s[i]-'a']--;
            int even_res = 0, odd_res = 0;

            for (int j = 0; j < 26; j++) {
                even_res = max(even_res, prefix[0][j] + suffix[1][j]);
                odd_res = max(odd_res, prefix[1][j] + suffix[0][j]);
            }

            res = min(res, (int) s.size() - even_res - odd_res);
            prefix[i%2][s[i]-'a']++;
        }
    }

    return res;
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << eval() << endl;
    
    return 0;
}






