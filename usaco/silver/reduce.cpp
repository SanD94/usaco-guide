// https://usaco.org/index.php?page=viewproblem2&cpid=642
#include <algorithm>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

enum Side { LEFT, BOTTOM, RIGHT, TOP };

int rect_val(vector<pair<int, int>> &cows, vector<bool> &mark) {
    int b = 40'000, t = 0, l = 40'000, r = 0;
    for (int i = 0; i < cows.size(); i++) {
        if (mark[i])
            continue;
        l = min(l, cows[i].first);
        b = min(b, cows[i].second);
        r = max(r, cows[i].first);
        t = max(t, cows[i].second);
    }
    return (t - b) * (r - l);
}

int eval() {
    int N;
    array<vector<pair<int, int>>, 4> points;
    vector<pair<int, int>> cows;
    int x, y;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        cows.push_back({x, y});
        points[LEFT].push_back({x, i});
        points[RIGHT].push_back({-x, i});
        points[TOP].push_back({-y, i});
        points[BOTTOM].push_back({y, i});
    }

    int res = 40'000 * 40'000;
    for (int i = 0; i < points.size(); i++)
        sort(points[i].begin(), points[i].end());

    for (int i = 0; i < 64; i++) {
        vector<bool> mark(N);
        array<int, 4> cnt{};
        for (int j = 0; j < 3; j++) {
            Side side = static_cast<Side>((i >> (j * 2)) & 3);
            mark[points[side][cnt[side]].second] = true;
            cnt[side]++;
        }
        res = min(res, rect_val(cows, mark));
    }
    return res;
}

int main() {
    set_io("reduce");
    cout << eval() << endl;
    return 0;
}
