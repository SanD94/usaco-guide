// https://usaco.org/index.php?page=viewproblem2&cpid=783
#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

enum Side {BOTTOM, RIGHT, TOP, LEFT};
const array<Side, 4> sides = {BOTTOM, RIGHT, TOP, LEFT};

Side cw(Side s) {
    return sides[(s + 1) % sides.size()];
}

Side ccw(Side s) {
    return sides[(s + sides.size() - 1) % sides.size()];
}

struct rect {
    array<int, 4> edge;
    
    friend istream &operator>>(istream &is, rect &r) {
        return is >> r.edge[LEFT] >> r.edge[BOTTOM]
                  >> r.edge[RIGHT] >> r.edge[TOP];
    }

    int width() const {
        return edge[RIGHT] - edge[LEFT];
    }

    int height() const {
        return edge[TOP] - edge[BOTTOM];
    }

    int area() const {
        return width() * height();
    }
};

rect b0, b1;

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

bool same_edge(const rect &a, const rect &b, Side s) {
    return a.edge[s] == b.edge[s];
}

bool cover_side(const rect &a, const rect &b, Side s) {
    return same_edge(a, b, s) &&
           same_edge(a, b, cw(s)) &&
           same_edge(a, b, ccw(s));
}

bool one_rect_left(const rect &orig, const rect &cov) {
    for (Side s : sides) 
        if (cover_side(cov, orig, s)) 
            return true;
    return false;
}

int eval() {
    rect cov = inter(b0, b1);
    bool ok = one_rect_left(b0, cov);

    // If the visible part is still one rectangle, tarp only that part.
    // Otherwise, one rectangular tarp must still cover all of b0.
    return b0.area() - cov.area() * ok;
}

int main() {
    set_io("billboard");
    cin >> b0 >> b1;
    cout << eval() << endl;
    return 0;
}
