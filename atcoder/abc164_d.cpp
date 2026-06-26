// https://atcoder.jp/contests/abc164/tasks/abc164_d
#include <iostream>
#include <vector>
using namespace std;

#define MOD 2019
using lli = long long int;


int main() {
    string s;
    cin >> s;
    lli res = 0, cur = 0, base = 1;
    vector<lli> cnt(MOD);
    cnt[0] = 1;


    for (int i = s.size()-1; i >= 0; i--) {
        cur = (cur + base * (s[i] - '0')) % MOD;
        
        res += cnt[cur];

        cnt[cur]++;
        base = (base * 10) % MOD;
    }

    cout << res << endl;

    return 0;
}

