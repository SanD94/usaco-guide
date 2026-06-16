// https://codeforces.com/problemset/problem/1555/B
#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

using lli = long long int;


enum Side {LEFT, BOTTOM, RIGHT, TOP};

struct rect {
    array<lli, 4> edge;
    
    friend istream &operator>>(istream &is, rect &r) {
        return is >> r.edge[LEFT] >> r.edge[BOTTOM]
                  >> r.edge[RIGHT] >> r.edge[TOP];
    }

    lli width() const {
        return edge[RIGHT] - edge[LEFT];
    }

    lli height() const {
        return edge[TOP] - edge[BOTTOM];
    }
};

lli fit(rect area, rect table, rect other) {
    lli res = 1e10;

    if (table.width() + other.width() <= area.width()) {
        res = min(res, max(0LL, other.width() - table.edge[LEFT]));
        res = min(res, max(0LL, other.width() - (area.width() - table.edge[RIGHT])));
    }

    if (table.height() + other.height() <= area.height()) {
        res = min(res, max(0LL, other.height() - table.edge[BOTTOM]));
        res = min(res, max(0LL, other.height() - (area.height() - table.edge[TOP])));
    }

    if (res == 1e10)
        return -1;
    return res;
}


lli eval() {
    int w, h;
    cin >> w >> h;
    rect big {{{0, 0, w, h}}};
    rect table;
    cin >> table;
    cin >> w >> h;
    rect other {{{0, 0, w, h}}};
    return fit(big, table, other);
}


int main() {
    int t;
    cin >> t;
    while (t--)
        cout << eval() << endl;
    
    return 0;
}
