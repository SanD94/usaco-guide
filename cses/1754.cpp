// https://cses.fi/problemset/task/1754
#include <iostream>
#include <cmath>
using namespace std;

using lli = long long int;

int main()
{
    int t;
    lli a, b;
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        bool is_possible = true;
        if ((a + b) % 3 != 0)
            is_possible = false;
        lli k = abs(a - b);
        if (k > min(a, b))
            is_possible = false;
        cout << (is_possible ? "YES" : "NO") << endl;
    }

    return 0;
}