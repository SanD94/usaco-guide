// https://usaco.org/index.php?page=viewproblem2&cpid=939
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
    set_io("buckets");
    string farm;
    int bx, by, rx, ry, lx, ly;
    int res = 0;

    for(int i = 0; i < 10; i++){
        cin >> farm;
        for (int j = 0; j < 10; j++) {
            if (farm[j] == 'B') {
                bx = i; by = j; 
            }
            if (farm[j] == 'R') {
                rx = i; ry = j;
            }
            if (farm[j] ==  'L') {
                lx = i; ly = j;
            }
        }
    }

    if (bx == rx && rx == lx) {
        if (by < ry && ry < ly) res += 2;
        if (ly < ry && ry < by) res += 2;
    } 
    if (by == ry && ry == ly) {
        if (bx < rx && rx < lx) res += 2;
        if (lx < rx && rx < bx) res += 2;
    }
    res += abs(bx - lx) + abs(by - ly) - 1;
    
    cout <<  res << endl;
    return 0;
}
