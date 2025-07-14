// https://cses.fi/problemset/task/1617
#include <iostream>
using namespace std;

#define MOD 1e9 + 7

using lli = long long int;

lli pow_mod(lli base, lli exp, lli mod)
{
    lli result = 1;
    base %= mod;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    cout << pow_mod(2, n, MOD) << endl;
}