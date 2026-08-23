// https://usaco.org/index.php?page=viewproblem2&cpid=1449
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int N;

size_t cnt_group_up(vector<int>& next, int x) {
    size_t res = 0;
    int cur_p = next[0];
    while (cur_p) {
        res++;
        if (cur_p + x + 1 > N) break;
        cur_p = next[cur_p + x + 1];
    }
    return res;
}

void up_sol(vector<int>& group, vector<int>& pos_label) {
    vector<int> nxt(N + 1, 0);

    for (int i : pos_label) nxt[i] = i;
    for (int i = N-1; i >= 0; i--)
        if (!nxt[i]) nxt[i] = nxt[i+1];

    for (int x = 1; x <= N; x++)
        group[x] += cnt_group_up(nxt, x);
}

size_t cnt_group_down(vector<int>& pos, int x) {
    size_t l = 0, r = 0, res = 0;
    while (l < pos.size()) {
        res++;
        while (r < pos.size() && pos[r] - pos[l] <= x) r++;
        l = r;
    }
    return res;
}

void down_sol(vector<int>& group, vector<int>& pos_label) {
    for (size_t g = 1; g <= pos_label.size(); g++) {
        size_t l = 0, r = N + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (cnt_group_down(pos_label, m) < g) r = m; 
            else l = m + 1;
        }
        group[1]++;
        group[l]--;
    }
}

vector<int> eval(vector<vector<int>>& pos, int N) {
    vector<int> up_res(N+1, 0), down_res(N+2, 0), res(N+1, 0);
    size_t lim = (int)sqrt(N);

    for (auto &p : pos)
        if (p.size() >= lim) up_sol(up_res, p);
        else down_sol(down_res, p);
    for (int i = 1; i < N; i++) down_res[i+1] += down_res[i];
    for (int i = 1; i <= N; i++) res[i] = up_res[i] + down_res[i];
    return res;
}


int main() {
    int label;
    cin >> N;
    vector<vector<int>> pos(N+1, vector<int>());
    for (int i = 1; i <= N; i++) {
        cin >> label;
        pos[label].push_back(i);
    }

    auto group = eval(pos, N);
    copy(begin(group) + 1, end(group), ostream_iterator<int>(cout, "\n"));

    return 0;
}

