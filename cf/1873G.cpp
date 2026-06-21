// https://codeforces.com/problemset/problem/1873/G
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int eval() {
    string s;
    cin >> s;
    vector<int> cnt_a;
    int i = 0;
    while (i < s.size()) {
        int cnt = 0;
        while(s[i] == 'A' && i < s.size()) { i++; cnt++; }
        cnt_a.push_back(cnt);
        i++;
    }
    if (s[s.size() - 1] == 'B') cnt_a.push_back(0);
    int sum = 0, mn = cnt_a[0];
    for (auto &e : cnt_a) {
        sum += e;
        mn = min(e, mn);
    }
    return sum - mn;
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << eval() << endl;
    
    return 0;
}




