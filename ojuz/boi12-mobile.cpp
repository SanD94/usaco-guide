// https://oj.uz/problem/view/BOI12_mobile
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>
#include <cmath>
using namespace std;


using ll = long long;


struct point {
    double x, y;
    friend istream& operator>>(istream& is, point& p) {
        return is >> p.x >> p.y;
    }

    friend ostream& operator<<(ostream& os, const point& p) {
        return os << p.x << " " << p.y;
    }
};

using radie = point;
const double EPS = 1e-6, MAXX = 1e10;


double dist(point x, point y) {
    double x_diff = x.x - y.x;
    double y_diff = x.y - y.y;
    return sqrt(x_diff * x_diff + y_diff * y_diff);
}

double get_x(point x, double dist, bool is_left = true) {
    double left_x = dist * dist - x.y * x.y;
    return x.x + (1 - 2 * is_left) * sqrt(left_x);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    double L;
    cin >> N >> L;

    vector<point> towers;
    copy_n(istream_iterator<point>(cin), N, back_inserter(towers));

    double l = 0, r = MAXX;

    while ((r - l) > EPS) {
        double m = l + (r - l) / 2;
        double traced = 0;
        for (int i = 0; i < N; i++) {
            double cur_dist = dist(towers[i], {traced, 0});
            if (cur_dist <= m && get_x(towers[i], m) <= traced)
                traced = max(traced, get_x(towers[i], m, false));
        }

        if (traced >= L) r = m;
        else l = m;
    }


    cout << fixed << setprecision(10) << l << endl;

    return 0;
}


