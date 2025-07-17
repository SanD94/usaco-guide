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
    set_io("word");
    int n, k, left;
    string s = "";
    bool is_print = false;
    cin >> n >> k;
    for (int i = 0, left = k; i < n; i++, cout << s, left -= s.length(), is_print = true) {
        cin >> s;
        if (s.length() > left) {
            cout << endl;
            left = k;
            continue;
        }
        if (is_print) cout << " ";
    }
    return 0;
}
