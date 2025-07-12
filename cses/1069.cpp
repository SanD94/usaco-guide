// https://cses.fi/problemset/task/1069
#include<iostream>
#include<cmath>
using namespace std;


int main() {
    string s;
    char ch = ' ';
    int res = 1, cnt = 0;

    cin >> s;
    for (auto &c : s) {
        if (ch != c) {
            cnt = 1;
            ch = c;
            continue;
        }
        cnt ++;
        res = max(res, cnt);
    }
    
    cout << res << endl;
}