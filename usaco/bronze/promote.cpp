// https://usaco.org/index.php?page=viewproblem2&cpid=591
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
    set_io("promote");
    int before[4], after[4], res[4];
    for (int i = 0; i < 4; i++) 
        cin >> before[i] >> after[i];
    for (int i = 3; i > 0; i--) {
        res[i] = after[i] - before[i];
        after[i-1] += res[i];
    }
    for (int i = 1; i < 4; i++)
        cout << res[i] << endl;
    return 0;
}
