// https://usaco.org/index.php?page=viewproblem2&cpid=1064
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

#define all(x) begin(x), end(x)

struct dir {
    int id, x, y;
    friend bool operator<(const dir& lhs, const dir& rhs) {
        return tie(lhs.x, lhs.y) < tie(rhs.x, rhs.y);
    }

    friend int operator-(const dir& lhs, const dir& rhs) {
        return (lhs.x - rhs.x) + (lhs.y - rhs.y);
    }
};

struct north_dir: public dir {
    friend bool operator<(const north_dir& lhs, const north_dir& rhs) {
        return tie(lhs.x, lhs.y) < tie(rhs.x, rhs.y);
    }
};


struct east_dir: public dir {
    friend bool operator<(const east_dir& lhs, const east_dir& rhs) {
        return tie(lhs.y, lhs.x) < tie(rhs.y, rhs.x);
    }
};


int main() {
    int n, x, y;
    char c;
    vector<north_dir> nm;
    vector<east_dir> em;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c >> x >> y;
        if (c == 'E') em.push_back({i, x, y });
        else nm.push_back({i, x, y });
    }

    sort(all(em));
    sort(all(nm));

    vector<int> killer(n, -1);
    vector<int> res(n);


    for (const auto& n : nm)
    for (const auto& e : em) {
        auto [nid, nx, ny] = n;
        auto [eid, ex, ey] = e;
        if (killer[nid] != -1 || killer[eid] != -1) continue;

        dir t{-1, nx, ey};
        if (t < n || t < e) continue;

        int diff_n = t - n, diff_e = t - e;
        if (diff_n < diff_e) { // north is the killer
            res[nid] += 1 + res[eid];
            killer[eid] = nid;
        } else if (diff_e < diff_n) {
            res[eid] += 1 + res[nid];
            killer[nid] = eid;
        }
        
    }

    copy(all(res), ostream_iterator<int>(cout, "\n"));
    return 0;
}


