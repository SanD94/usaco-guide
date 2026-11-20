// https://codeforces.com/problemset/problem/1472/E
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

#define all(x) begin(x), end(x)

using ll = long long;

struct body {
    int shorter, longer, idx;
    friend bool operator<(const body& lhs, const body& rhs) {
        return tie(lhs.shorter, lhs.longer) < tie(rhs.shorter, rhs.longer);
    }
};



int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, w, h;
        vector<body> bodies;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> w >> h;
            bodies.push_back({ min(w, h), max(w, h), i });
        }
        sort(all(bodies));

        vector<pair<int,int>> small_longer(n);
        int cur_small_longer = bodies[0].longer, cur_idx = 0;

        for (int i = 0; i < n; i++) {
            if (cur_small_longer > bodies[i].longer) {
                cur_small_longer = bodies[i].longer;
                cur_idx = i;
            }
            small_longer[i] = {cur_small_longer, cur_idx};
        }


        vector<int> res(n+1, -1);
        auto short_comp = [](const body& lhs, const body& rhs) {
            return lhs.shorter < rhs.shorter;
        };

        for (int i = 0; i < n; i++) {
            auto elem = lower_bound(all(bodies), bodies[i], short_comp);
            
            if (elem == bodies.begin()) continue;
            int idx = elem - bodies.begin() - 1;
            if (bodies[small_longer[idx].second].longer < bodies[i].longer)
                res[bodies[i].idx] = bodies[small_longer[idx].second].idx;
        }

        for(int i = 1; i < n; i++) cout << res[i] << " ";
        cout << res.back() << endl;
    }

    return 0;
}




