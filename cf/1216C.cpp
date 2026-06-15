// https://codeforces.com/contest/1216/problem/C
#include <iostream>
#include <array>
#include <vector>
using namespace std;

using lli = long long int;


enum Side {BOTTOM, RIGHT, TOP, LEFT};

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

    lli area() const {
        return width() * height();
    }
};

rect w0, b0, b1;

rect inter(const rect &a, const rect &b) {
    rect res;
    res.edge[LEFT] = max(a.edge[LEFT], b.edge[LEFT]);
    res.edge[BOTTOM] = max(a.edge[BOTTOM], b.edge[BOTTOM]);
    res.edge[RIGHT] = min(a.edge[RIGHT], b.edge[RIGHT]);
    res.edge[TOP] = min(a.edge[TOP], b.edge[TOP]);

    if (res.width() <= 0 || res.height() <= 0)
        return {{{0, 0, 0, 0}}};
    return res;
}

string eval() {
    vector<string> res = { "NO", "YES" };

    lli cover = inter(w0, b0).area() 
        + inter(w0, b1).area()
        - inter(inter(w0, b0), b1).area();

    bool ok = (w0.area() - cover) > 0;
    return res[ok];
}


int main() {
    cin >> w0 >> b0 >> b1;
    cout << eval() << endl;
    return 0;
}
