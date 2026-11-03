// https://cses.fi/problemset/task/1619
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

struct vst {
    int time;
    int dir;
    friend bool operator<(const vst& lhs, const vst& rhs) {
        return lhs.time < rhs.time;
    }
};

int main() {
    int n;
    vector<vst> visits;
    cin >> n;
    int l, r;
    for (int i = 0; i < n; i++) {
        cin >> l >> r;
        visits.push_back({l, 1});
        visits.push_back({r, -1});
    }

    sort(all(visits));
    int res = 0, cur_visit = 0;
    for (auto const [t, dir]: visits) {
        cur_visit += dir;
        res = max(res, cur_visit);
    }
    cout << res << endl;

    return 0;
}

