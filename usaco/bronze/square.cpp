// https://usaco.org/index.php?page=viewproblem2&cpid=663
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


rect b0, b1;

int eval() {
    int xbr = min(b0.p1.x, b1.p1.x);
    int ybr = min(b0.p1.y, b1.p1.y);
    int xrt = max(b0.p2.x, b1.p2.x);
    int yrt = max(b0.p2.y, b1.p2.y);
    int res = max(xrt - xbr, yrt - ybr);
    return res * res;
}

int main() {
    set_io("square");
    cin >> b0 >> b1;
    cout << eval() << endl;
    return 0;
}



