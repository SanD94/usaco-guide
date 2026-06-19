// https://codeforces.com/problemset/problem/1624/D
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

using lli = long long int;



int eval() {
    int n, k;
    string s;
    vector<int> cnt(26);

    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        cnt[s[i]-'a']++;

    int par = 0;
    int odd = 0;
    for (auto count : cnt) {
        if (count % 2)
            odd++;
        par += count / 2;
    }
    int res = 0;
    res += (par / k) * 2;
    res += min(1, ((par % k) * 2 + odd) / k);

    return res;
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << eval() << endl;
    
    return 0;
}


