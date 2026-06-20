// https://usaco.org/index.php?page=viewproblem2&cpid=509
#include <iostream>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int get_10(int num, int base) {
    int res = 0;
    int cur = 1;
    while (num) {
        res += (num % 10) * cur;
        cur *= base;
        num /= 10;
    }
    return res;
}

int get_base(int num, int basenum) {
    int lo = 10, hi = 15'000;
    while (lo <= hi) {
        int mid = (hi + lo) / 2;
        int cur_num = get_10(basenum, mid);
        if (cur_num < num) lo = mid + 1;
        else if (cur_num > num) hi = mid - 1;
        else return mid;
    }
    return -1;
}

void eval() {
    int a, b;
    cin >> a >> b;
    for (int i = 10; i <= 15'000; i++) {
        int num = get_10(a, i);
        int y = get_base(num, b);
        if (y != -1) {
            cout << i << " " << y << endl;
            return;
        }
    }
}

int main() {
    set_io("whatbase");
    int k;
    cin >> k;
    while (k--) eval();
    return 0;
}



