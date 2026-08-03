// https://usaco.org/index.php?page=viewproblem2&cpid=1303
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <tuple>
using namespace std;


#define all(x) begin(x), end(x)

using lli = long long int;

struct event {
    lli x, y, t;
    
    friend istream& operator>>(istream& is, event &e) {
        return is >> e.x >> e.y >> e.t;
    }

    friend bool operator<(const event& lhs, const event& rhs) {
        return tie(lhs.t, lhs.x, lhs.y) < tie(rhs.t, rhs.x, rhs.y);
    }
};

lli get_sq(lli x0, lli x1) {
    return (x0-x1) * (x0-x1);
}

lli distance(lli x0, lli y0, lli x1, lli y1) {
    return get_sq(x0, x1) + get_sq(y0, y1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, q;
    cin >> n >> q;
    vector<event> grazing(n), cows(q);

    copy_n(istream_iterator<event>(cin), n, begin(grazing));
    copy_n(istream_iterator<event>(cin), q, begin(cows));

    sort(all(grazing));
    int res = 0;
    for (const auto &c : cows) {
        auto up = lower_bound(all(grazing), c);
        auto low = up != grazing.begin() ? up - 1 : grazing.begin();
        
        bool nearby = true;
        for (auto it : { low, up }) {
            auto [xi, yi, ti] = *it;
            auto [xc, yc, tc] = c;
            if (get_sq(ti, tc) < distance(xi, yi, xc, yc)) nearby = false;
        }

        if (!nearby) res++;
    }

    cout << res << endl;


    return 0;
}
