// https://usaco.org/index.php?page=viewproblem2&cpid=624
#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <iterator>
using namespace std;

#define all(x) begin(x), end(x)

struct point {
    int x, y;

    friend bool operator<(const point& lhs, const point& rhs) {
        return tie(lhs.x, lhs.y) < tie(rhs.x, rhs.y);
    }

    friend istream& operator>>(istream& is, point& p) {
        return is >> p.x >> p.y;
    }

    friend ostream& operator<<(ostream& os, const point& p) {
        return os << p.x << " " << p.y;
    }
};


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

// For each vertical cut, find the largest horizontal cut whose
// lower-left prefix contains at most lim cows.
vector<int> get_bounds(const vector<point>& cows, int lim) {
    int n = cows.size();
    vector<int> res(n + 1), y_frequency(n);
    int y_bound = n, count = 0;

    res[0] = y_bound;
    size_t cow_index = 0;
    for (int x = 1; x <= n; x++) {
        while (cow_index < cows.size() && cows[cow_index].x == x - 1) {
            int y = cows[cow_index++].y;
            y_frequency[y]++;
            if (y < y_bound) count++;
        }

        while (count > lim)
            count -= y_frequency[--y_bound];
        res[x] = y_bound;
    }

    return res;
}

bool can_balance(const vector<point>& sw, const vector<point>& se,
                 const vector<point>& nw, const vector<point>& ne, int lim) {
    int n = sw.size();
    vector<int> sw_bound = get_bounds(sw, lim);
    vector<int> se_bound = get_bounds(se, lim);
    vector<int> nw_bound = get_bounds(nw, lim);
    vector<int> ne_bound = get_bounds(ne, lim);

    for (int x = 0; x <= n; x++) {
        int bottom = min(sw_bound[x], se_bound[n - x]);
        int mirrored_top = min(nw_bound[x], ne_bound[n - x]);
        if (bottom + mirrored_top >= n) return true;
    }
    return false;
}


void compress(vector<point>& cows) {
    for (int point::*axis : {&point::x, &point::y}) {
        sort(all(cows), [axis](const point& a, const point& b) {
            return a.*axis < b.*axis;
        });
        int rank = 0, previous = cows[0].*axis;
        for (point& cow : cows) {
            int coordinate = cow.*axis;
            if (coordinate != previous) {
                previous = coordinate;
                rank++;
            }
            cow.*axis = rank;
        }
    }
    sort(all(cows));
}


int main() {
    set_io("balancing");
    int N;
    vector<point> cows;

    cin >> N;
    copy_n(istream_iterator<point>(cin), N, back_inserter(cows));

    compress(cows);
    vector<point> sw = cows, se = cows, nw = cows, ne = cows;
    for (point &cow: se) cow.x = N - 1 - cow.x;
    for (point &cow: nw) cow.y = N - 1 - cow.y;
    for (point &cow: ne) {
        cow.x = N - 1 - cow.x;
        cow.y = N - 1 - cow.y;
    }
    sort(all(se));
    sort(all(nw));
    sort(all(ne));

    int l = 0, r = N;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (can_balance(sw, se, nw, ne, m)) r = m;
        else l = m + 1;
    }

    cout << l << endl;

    return 0;
}
