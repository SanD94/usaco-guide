// https://usaco.org/index.php?page=viewproblem2&cpid=567
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
    set_io("paint");
    int a, b, c, d, res;

    cin >> a >> b >> c >> d;

    if (b <= c || d <= a)
        res = b - a + d - c;
    else {
        int s = min(a, c);
        int e = max(b, d);
        res = e - s;
    }
    cout << res << endl;
    return 0;
}
