// https://usaco.org/index.php?page=viewproblem2&cpid=807
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
    set_io("teleport");
    int a, b, x, y;

    cin >> a >> b >> x >> y;
    int res = abs(a - b);
    res = min(res, abs(a - x) + abs(b - y));
    res = min(res, abs(a - y) + abs(b - x));
    cout << res << endl;
    return 0;
}
