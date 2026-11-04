// https://usaco.org/index.php?page=viewproblem2&cpid=786
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <iterator>
using namespace std;


#define all(x) begin(x), end(x)

struct guard {
    int start, stop;

    friend bool operator<(const guard &lhs, const guard &rhs) {
        return tie(lhs.start, lhs.stop) < tie(rhs.start, rhs.stop);
    }

};

struct gtime {
    int time;
    int dir;

    friend bool operator<(const gtime& lhs, const gtime& rhs) {
        return tie(lhs.time, lhs.dir) < tie(rhs.time, rhs.dir);
    }

    friend bool operator>(const gtime& lhs, const gtime& rhs) {
        return rhs < lhs;
    }
};


void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}


int main() {
    set_io("lifeguards");

    int N;
    vector<guard> guards;
    vector<gtime> timeline;
    cin >> N;
    vector<int> single_prefix(2*N);
   
    int l, r;
    for (int i = 0; i < N; i++) {
        cin >> l >> r;

        guards.push_back({ l , r });
        timeline.push_back({ l, 1 });
        timeline.push_back({ r, -1 });
    }

    sort(all(timeline));

    int cur_cnt_shift = 1;
    int total = 0, cur_time = timeline[0].time;
    int res = 0;

    for (size_t i = 1; i < timeline.size(); i++) {
        auto [time, dir] = timeline[i];
        single_prefix[i] = single_prefix[i-1];

        if (cur_cnt_shift != 0) total += time - cur_time;
        if (cur_cnt_shift == 1) single_prefix[i] += time - cur_time;

        cur_time = time;
        cur_cnt_shift += dir;
    }


    for(const auto [s, e]: guards) {
        auto sidx = distance(timeline.begin(), lower_bound(all(timeline), gtime{s, 1}));
        auto eidx = distance(timeline.begin(), lower_bound(all(timeline), gtime{e, -1}));
        auto tot_remove = single_prefix[eidx] - single_prefix[sidx]; 
        res = max(res, total - tot_remove);
    }

    cout << res << endl;
    

    return 0;
}

