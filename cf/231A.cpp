// https://codeforces.com/problemset/problem/231/A
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int t, res = 0;
    int a, b, c;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> c;
        if (a + b + c >= 2)
            res++;
    }
    cout << res << endl;
    return 0;
}
