// https://usaco.org/index.php?page=viewproblem2&cpid=744
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

struct rect {
    int x1, x2;
    int y1, y2;
};

map<int, rect> rects;
vector<vector<int>> canvas;
vector<vector<int>> diff;
int n;

void read() {
    int idx;
    cin >> n;
    canvas.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> idx;
            if (idx == 0) continue;
            if (rects.count(idx) == 0)
                rects[idx] = { i, i, j, j };
            rect r = {
                min(rects[idx].x1, i),
                max(rects[idx].x2, i), 
                min(rects[idx].y1, j),
                max(rects[idx].y2, j)
            };
            canvas[i][j] = idx;
            rects[idx] = r;
        }
}

void preprocess() {
    diff.assign(n+1, vector<int>(n+1));
    for (auto &[idx, b] : rects) {
        auto [x1, x2, y1, y2] = b;
        diff[x1][y1]++;
        diff[x1][y2+1]--;
        diff[x2+1][y1]--;
        diff[x2+1][y2+1]++;
    }
}

int eval() {
    int res = n*n - rects.size();
    if (rects.size() <= 1) return res;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i > 0) diff[i][j] += diff[i-1][j];
            if (j > 0) diff[i][j] += diff[i][j-1];
            if (i > 0 && j > 0) diff[i][j] -= diff[i-1][j-1];
            if (diff[i][j] > 1) rects.erase(canvas[i][j]);
        }
    res += rects.size();
    return res;
}


int main() {
    set_io("art");
    read();
    preprocess();
    cout << eval() << endl;
    return 0;
}



