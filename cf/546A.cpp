// https://codeforces.com/problemset/problem/546/A
#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int k, n, w;
    cin >> k >> n >> w;
    int c = k * (w * (w + 1)) / 2;
    cout << max(0, c - n) << endl;
    return 0;
}
