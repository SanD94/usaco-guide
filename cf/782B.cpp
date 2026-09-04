// https://codeforces.com/contest/782/problem/B
#include <iomanip>
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

#define all(x) begin(x), end(x)

const double RES_MAX = 1e9;
const double EPS = 1e-6;

struct neigh {
    int x, v;
    friend bool operator<(const neigh& lhs, const neigh& rhs) {
        return tie(lhs.x, lhs.v) < tie(rhs.x, rhs.v);
    }
};

int main() {
    int n;
    cin >> n;
    vector<neigh> friends(n);
    for (int i = 0; i < n; i++) cin >> friends[i].x;
    for (int i = 0; i < n; i++) cin >> friends[i].v;
    sort(all(friends));
    double l = 0, r = RES_MAX;
    while ((r-l) >= EPS) {

        double t = l + (r - l) / 2;
        double min_right = RES_MAX;
        bool is_met = true;

        for (int i = 0; i < n; i++) 
            min_right = min(min_right, friends[i].x + t * friends[i].v);

        for (int i = n - 1; i >= 0; i--)
            if (friends[i].x - t * friends[i].v > min_right) {
                is_met = false;
                break;
            }

        if (is_met) r = t;
        else l = t;
    }

    cout << fixed << setprecision(12) << l << endl;
    return 0;
}

