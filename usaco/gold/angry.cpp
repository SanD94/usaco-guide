// https://usaco.org/index.php?page=viewproblem2&cpid=597
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

template <typename Iter>
vector<int> step(Iter begin, Iter end) {
    int size = (int)distance(begin, end);
    vector<int> res(size);
    if (size == 0) return res;

    auto cost = [&](int i, int k) {
        int gap = abs(*(begin + i) - *(begin + k));
        return max(gap, res[k] + 2);
    };

    // no next blast. cancels the later +2.
    res[0] = -2;
    int l = 0;

    for (int r = 1; r < size; r++) {
        while (l + 1 < r && cost(r, l + 1) <= cost(r, l)) l++;
        res[r] = cost(r, l);
    }

    return res;
}

template <typename InputIt, typename Size, typename OutputIt, typename Op>
OutputIt transform_n(InputIt input, Size size, OutputIt output, Op op) {
    for (Size i = 0; i < size; i++)
        *output++ = op(*input++);
    return output;
}

bool manage(const vector<int>& cows, 
            const vector<int>& left,
            const vector<int>& right, int R) {
    // first triggered blast has power - 2.
    int l_idx = upper_bound(left.begin(), left.end(), R - 2) - left.begin() - 1;
    int r_offset = upper_bound(right.begin(), right.end(), R - 2) - right.begin() - 1;
    int r_idx = cows.size() - 1 - r_offset;

    // one center must reach both frontiers.
    return cows[r_idx] - cows[l_idx] <= 2 * R;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set_io("angry");
    int n;
    cin >> n;
    vector<int> cows(n);
    // doubled units: half-powers integral, each step loses 2.
    transform_n(istream_iterator<int>(cin), n, begin(cows), [](int cow) { return cow * 2; });

    sort(all(cows));

    vector<int> left = step(begin(cows), end(cows)), right = step(rbegin(cows), rend(cows));

    // reaching both endpoints always works.
    int l = 0, r = (cows.back() - cows.front() + 1) / 2;
    while (l < r) {
        int mid = l + (r - l) / 2;
        if (manage(cows, left, right, mid)) r = mid;
        else l = mid + 1;
    }

    cout << fixed << setprecision(1) << l / 2.0 << '\n';

    return 0;
}
