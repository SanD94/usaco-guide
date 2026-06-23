// https://dmoj.ca/problem/coci17c5p2
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int n, m, k;
int x, y, cw;
vector<vector<int>> elem;
vector<pair<int,int>> ddir = {
    {-1, 0}, {0, 1}, {1, 0}, {0, -1}
};

enum Dir {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3,
    DIR_SIZE = 4
};

struct spiral {
    int x, y;
    int n = 1;

    vector<int> t = {1, 1};

    int seg = 0, used = 0;

    int curDir = UP;

    spiral(int startX = 0, int startY = 0)
    : x(startX), y(startY) {}

    pair<int, int> next() {
        pair<int, int> ans = {x, y};

        advance();
        update_state();

        return ans;
    }

private:
    void advance() {
        auto [dx, dy] = ddir[curDir];
        x += dx;
        y += dy;
    }

    void update_state() {
        used++;

        if (used != t[seg]) return;

        used = 0;
        seg++;

        curDir = (curDir + 1) % DIR_SIZE;

        if (seg != (int)t.size()) return;

        seg = 0;
        n++;
        t = {n, n};
    }
};

bool is_inside(int x, int y) {
    return !(x < 0 || n <= x || y < 0 || m <= y);
}


int main() {
    cin >> n >> m >> k;

    elem.assign(n, vector<int>(m, 10'010));
    
    int x, y, ccw;
    for(int i = 0; i < k; i++) {
        cin >> x >> y >> ccw;
        x --; y --;
        spiral s(x, y);
        for (int i = 0; i < 10'000; i++) {
            auto [cx, cy] = s.next();
            if (ccw) cy = y + (y - cy);
            if (is_inside(cx, cy))
                elem[cx][cy] = min(elem[cx][cy], i+1);
        }
    }

    for (int i = 0; i < n; i++) {
        copy(begin(elem[i]), end(elem[i]), ostream_iterator<int>(cout, " "));
        cout << endl;
    }
    return 0;
}

