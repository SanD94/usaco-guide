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

struct bounds {
    vector<int> bottom_max, top_min;
};

// Accumulate one side of the vertical fence. For every vertical cut,
// bottom_max is the largest horizontal cut with at most lim cows below it,
// and top_min is the smallest cut with at most lim cows above it.
bounds get_bounds(const vector<point>& cows, int lim) {
    int n = cows.size();
    bounds res{vector<int>(n + 1), vector<int>(n + 1)};
    vector<int> y_frequency(n);
    int bottom_max = n, top_min = 0;
    int bottom_count = 0, top_count = 0;

    auto add = [&](const point& cow) {
        int y = cow.y;
        y_frequency[y]++;
        if (y < bottom_max) bottom_count++;
        if (y >= top_min) top_count++;
    };
    auto update_bounds = [&] {
        while (bottom_count > lim) 
            bottom_count -= y_frequency[--bottom_max];
        
        while (top_count > lim) 
            top_count -= y_frequency[top_min++];
    };

    res.bottom_max[0] = bottom_max;
    res.top_min[0] = top_min;
    size_t cow_index = 0;
    for (int cut = 1; cut <= n; cut++) {
        while (cow_index < cows.size() && cows[cow_index].x == cut - 1)
            add(cows[cow_index++]);
        
        update_bounds();
        res.bottom_max[cut] = bottom_max;
        res.top_min[cut] = top_min;
    }

    return res;
}

bool can_balance(const vector<point>& cows, const vector<point>& mirrored,
                 int lim) {
    int n = cows.size();
    bounds left = get_bounds(cows, lim);
    bounds right = get_bounds(mirrored, lim);

    for (int x = 0; x <= n; x++) {
        int lower = max(left.top_min[x], right.top_min[n - x]);
        int upper = min(left.bottom_max[x], right.bottom_max[n - x]);
        if (lower <= upper) return true;
    }
    return false;
}


void compress(vector<point>& cows) {
    sort(all(cows));
    int i = 0;
    int cur_i = cows[0].x;
    for (auto &c: cows) {
        if (c.x != cur_i) {
            cur_i = c.x;
            i++;
        }
        c.x = i;
    }

    sort(all(cows), [](const point& lhs, const point &rhs) {
        return tie(lhs.y, lhs.x) < tie(rhs.y, rhs.x);
    });
    i = 0, cur_i = cows[0].y;
    for (auto &c: cows) {
        if (c.y != cur_i) {
            cur_i = c.y;
            i++;
        }
        c.y = i;
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
    vector<point> mirrored = cows;
    for (point &cow: mirrored) cow.x = N - 1 - cow.x;
    sort(all(mirrored));

    int l = 0, r = N;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (can_balance(cows, mirrored, m)) r = m;
        else l = m + 1;
    }

    cout << l << endl;

    return 0;
}
