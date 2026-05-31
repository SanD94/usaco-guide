// https://usaco.org/index.php?page=viewproblem2&cpid=1035
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int N;
string barns;
int res;



void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void eval() {
    vector<int> cows;
    for (int i = 0; i < N; i++) {
        if (barns[i] == '1') cows.push_back(i);
    }

    if (cows.empty()) {
        res = N - 1;
        return;
    }

    int min_dist = N;
    for (int i = 1; i < (int)cows.size(); i++) {
        min_dist = min(min_dist, cows[i] - cows[i - 1]);
    }

    int best_one = 0;
    int second_one = 0;
    int best_same = 0;

    auto add_gap = [&](int one_cow_dist) {
        if (one_cow_dist >= best_one) {
            second_one = best_one;
            best_one = one_cow_dist;
        } else if (one_cow_dist > second_one) {
            second_one = one_cow_dist;
        }
    };

    int left = cows[0];
    add_gap(left);
    best_same = max(best_same, left / 2);

    for (int i = 1; i < (int)cows.size(); i++) {
        int gap = cows[i] - cows[i - 1];
        add_gap(gap / 2);
        best_same = max(best_same, gap / 3);
    }

    int right = N - 1 - cows.back();
    add_gap(right);
    best_same = max(best_same, right / 2);

    res = min(min_dist, max(second_one, best_same));
}

int main() {
    set_io("socdist1");

    cin >> N;
    cin >> barns;
    eval();

    cout << res << endl;

    return 0;
}
