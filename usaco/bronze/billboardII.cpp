// https://usaco.org/index.php?page=viewproblem2&cpid=783
#include <iostream>
#include <vector>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct point {
    int x, y;
    friend istream &operator>>(istream &is, point &p) {
        return is >> p.x >> p.y;
    }

    point operator+(const point &p) const {
        return {x + p.x, y + p.y};
    }

    point operator-(const point &p) const {
        return {x - p.x, y - p.y};
    }
};

struct rect {
    point p1, p2;
    
    friend istream &operator>>(istream &is, rect &r) {
        return is >> r.p1 >> r.p2;
    }

    int area() {
        auto [x, y] = p2 - p1;
        if (x < 0 || y < 0) return 0;
        return x * y;
    }
};

int intersect(rect b, rect t) {
    point bl = { max(b.p1.x, t.p1.x), max(b.p1.y, t.p1.y) }; 
    point tr = { min(b.p2.x, t.p2.x), min(b.p2.y, t.p2.y) };
    return rect{bl, tr}.area();
}

vector<point> get_dots(rect r) {
    point bl = r.p1;
    point br = point{r.p2.x, r.p1.y};
    point tr = r.p2;
    point tl = point{r.p1.x, r.p2.y};
    vector<point> ps = { bl, br, tr, tl };
    return ps;
}

bool ccw(point ref, point a, point b) {
    point v0 = a - ref;
    point v1 = b - ref;
    int val = v0.x * v1.y - v0.y * v1.x;
    return val > 0;
}

bool is_inside(point p, vector<point> polygon) {
    int N = polygon.size();
    for (int i = 0; i < N; i++) {
        point cur = polygon[i];
        point next = polygon[(i + 1) % N];
        if (!ccw(cur, next, p)) return false;
    }
    return true;
}



int cnt_dot_inside(rect r, rect ref) {
    int cnt  = 0;
    auto ps = get_dots(r);
    auto ref_ps = get_dots(ref);
    for (const auto &p : ps) if (is_inside(p, ref_ps)) cnt++;
    return cnt;
}

rect b0, b1;

int eval() {
    int cover = intersect(b0, b1);
    int cnt = cnt_dot_inside(b0, b1); 
    return b0.area() - (cover * (cnt >= 2));
}

int main() {
    set_io("billboard");
    cin >> b0 >> b1;
    cout << eval() << endl;
    return 0;
}



