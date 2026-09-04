// https://codeforces.com/problemset/problem/1117/C
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;
const ll MAX_RES = 1e18;


struct point {
    ll x, y;

    point operator+(const point& p) const {
        return { x + p.x, y + p.y };
    }
    
    point operator-(const point& p) const {
        return { x - p.x, y - p.y };
    }

    point operator*(const ll a) const {
        return { a * x, a * y };
    }

    friend istream& operator>>(istream& is, point& p) {
        return is >> p.x >> p.y;
    }

    friend point operator*(ll a, const point& p) {
        return p * a;
    }

    ll abs_dist() {
        return abs(x) + abs(y);
    }
};

string dir_str = "ULDR";
size_t get_index(char c) {
    for (size_t i = 0; i < dir_str.size(); i++)
        if (dir_str[i] == c) return i;
    return -1;
}

vector<point> dirs = {
    {0, 1}, {-1, 0}, {0, -1}, {1, 0}
};

vector<point> get_prefix(string& s, int n) {
    vector<point> res(n+1);

    for (int i = 0; i < n; i++)
        res[i+1] = res[i] + dirs[get_index(s[i])];

    return res;
}




int main() {
    point source, dest;
    ll n;
    string s;
    cin >> source >> dest;
    cin >> n >> s;
    vector<point> p_arr = get_prefix(s, n);
    auto calc_prefix = [&](int i) {
        return p_arr[i] - p_arr[0];
    };

    ll l = 0, r = MAX_RES;
    while (l < r) {
        ll m = l + (r - l) / 2;
        point wind_cost = m / n * calc_prefix(n) + calc_prefix(m % n);
        ll tot_cost = (dest - (source + wind_cost)).abs_dist();
        if (tot_cost <= m) r = m;
        else l = m + 1;
    }

    if (l == MAX_RES) l = -1;
    cout << l << endl;
    return 0;
}


