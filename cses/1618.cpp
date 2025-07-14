// https://cses.fi/problemset/task/1618
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    while (n > 1)
    {
        res += n / 5;
        n /= 5;
    }
    cout << res << endl;
    return 0;
}