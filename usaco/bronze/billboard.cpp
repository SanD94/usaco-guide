// https://usaco.org/index.php?page=viewproblem2&cpid=759
#include <iostream>
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

rect b0, b1, truck;

int eval() {
    int tot_area = b0.area() + b1.area();
    int intb0 = intersect(b0, truck);
    int intb1 = intersect(b1, truck);
    return tot_area - intb0 - intb1;
}

int main() {
    set_io("billboard");
    cin >> b0 >> b1 >> truck;
    cout << eval() << endl;
    return 0;
}


