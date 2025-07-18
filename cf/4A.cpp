// https://codeforces.com/problemset/problem/4/A
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << (n % 2 == 0 && n > 2 ? "YES" : "NO") << endl;
    return 0;
}
