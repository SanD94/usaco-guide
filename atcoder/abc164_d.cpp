// https://atcoder.jp/contests/abc164/tasks/abc164_d
#include <iostream>
#include <vector>
using namespace std;

#define MOD 2019
using lli = long long int;



vector<lli> get_inverse() {
    vector<lli> res(MOD);
    for (int i = 1; i < MOD; i++) {
        if (res[i]) continue;
        for (int j = i; j < MOD; j++)
            if ((i * j) % MOD == 1) {
                res[i] = j;
                res[j] = i;
                break;
            }
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    lli res = 0, cur = 0, base = 1;
    vector<lli> cnt(MOD);
    cnt[0] = 1;

    auto inverse = get_inverse();

    for (int i = 0; i < s.size(); i++) {
        cur = (10 * cur + (s[i] - '0')) % MOD;
        lli rev_base = inverse[base];
        
        res += cnt[(rev_base * cur) % MOD];

        cnt[(rev_base * cur) % MOD]++;
        base = (base * 10) % MOD;
    }

    cout << res << endl;

    return 0;
}

