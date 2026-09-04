// https://codeforces.com/problemset/problem/1117/C
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;
const ll MAX_RES = 1e18;


struct point {
    ll x, y;

    point operator+(const point& p) const { return { x + p.x, y + p.y }; }
    point operator-(const point& p) const { return { x - p.x, y - p.y }; }
    point operator*(const ll a) const { return { a * x, a * y }; }

    friend point operator*(ll a, const point& p) { return p * a; }
    friend istream& operator>>(istream& is, point& p) { return is >> p.x >> p.y; }

    ll abs_dist() const { return abs(x) + abs(y); }
};


point get_dir(char c) {
    return {
        (c == 'R') - (c == 'L'),
        (c == 'U') - (c == 'D')
    };
}

vector<point> get_prefix(string& s, int n) {
    vector<point> res(n+1);

    for (int i = 0; i < n; i++)
        res[i+1] = res[i] + get_dir(s[i]);

    return res;
}


int main() {
    point source, dest;
    ll n;
    string s;
    cin >> source >> dest;
    cin >> n >> s;
    vector<point> p_arr = get_prefix(s, n);

    ll l = 0, r = MAX_RES;
    while (l < r) {
        ll m = l + (r - l) / 2;
        point wind_cost = m / n * p_arr[n] + p_arr[m % n];
        ll tot_cost = (dest - (source + wind_cost)).abs_dist();
        if (tot_cost <= m) r = m;
        else l = m + 1;
    }

    if (l == MAX_RES) l = -1;
    cout << l << endl;
    return 0;
}
