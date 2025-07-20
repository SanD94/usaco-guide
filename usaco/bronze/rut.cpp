// https://usaco.org/index.php?page=viewproblem2&cpid=1061
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

# define MAXRES 1e09+1
int N;
vector<tuple<int, int, int, int>> sections;


void eval(int cur, vector<int> &x, vector<int> &y, vector<bool> &dir) {
    // Intersection check
    for(int i = 0; i < N; i++) {
        if (!(dir[i] ^ dir[cur])) continue;
        if (x[cur] > x[i]) continue;
        if (y[cur] < y[i]) continue;
        int xdiff = x[i] - x[cur];
        int ydiff = y[cur] - y[i];
        if (xdiff <= ydiff) continue;
        sections.emplace_back(xdiff, cur, i, ydiff);
    }
}

void check_graph(vector<int> &res) {
    vector<int> mark(N);
    for (int i = 0; i < N; i++) res[i] = MAXRES;

    sort(sections.begin(), sections.end());
    for (const auto &s : sections) {
        int cand = get<1>(s);
        int blocker = get<2>(s);
        int dist = get<0>(s);
        int block_dist = get<3>(s);
        // tricky part with projection controller
        if (!mark[cand] && res[blocker] > block_dist) {
            mark[cand] = true;
            res[cand] = dist;
        }
    }
}

int main(int argc, char const *argv[]) {
    char c;
    int x, y;
    cin >> N;
    vector<int> cow_x(N);
    vector<int> cow_y(N);
    vector<bool> dir(N);
    vector<int> res(N);
    for (int i = 0; i < N; i++) {
        cin >> c >> x >> y;
        dir[i] = c == 'N';
        cow_x[i] = x;
        cow_y[i] = y;
    }
    // E&N same switch xy WLOG
    // i with E is the reference
    for (int i = 0; i < N; i++) {
        dir[i] ? 
            eval(i, cow_y, cow_x, dir) :
            eval(i, cow_x, cow_y, dir);
    }
    check_graph(res);
    for (int i = 0; i < N; i++)
        cout << (res[i] == MAXRES ? "Infinity" : to_string(res[i])) << endl;


    return 0;
}
