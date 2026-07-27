// https://usaco.org/index.php?page=viewproblem2&cpid=923
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 200;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    set_io("paintbarn");
    int n, k;
    cin >> n >> k;
    vector<vector<int>> diff(MAXN + 1, vector<int>(MAXN + 1));
    vector<vector<int>> leftovers(MAXN, vector<int>(MAXN));
    vector<vector<int>> p(MAXN + 1, vector<int>(MAXN + 1));

    // coating overlap
    int a, b, c, d;
    for(int i = 0; i < n; i++) {
        cin >> a >> b >> c >> d;
        diff[a][b]++;
        diff[a][d]--;
        diff[c][b]--;
        diff[c][d]++;
    }

    // intention is K. putting more means -1, completing is a good point +1
    int cnt = 0;
    for (int i = 0; i < MAXN; i++)
        for(int j = 0; j < MAXN; j++) {
            int up = (i - 1 >= 0 ? diff[i-1][j] : 0);
            int left = (j - 1 >= 0 ? diff[i][j-1] : 0);
            int upleft = ((i - 1 >= 0 && j - 1 >= 0) ? diff[i-1][j-1] : 0);
            diff[i][j] += up + left - upleft;
            if (diff[i][j] == k) {
                leftovers[i][j] = -1;
                cnt ++;
            }
            if (diff[i][j] == k-1) leftovers[i][j] = 1;
        }

    // always prefix to calculate any subregion
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            p[i+1][j+1] = p[i+1][j] + p[i][j+1] - p[i][j] + leftovers[i][j];

    auto rect_sum = [&](int x1, int y1, int x2, int y2) {
        return p[x2][y2] - p[x1][y2] - p[x2][y1] + p[x1][y1];
    };

    vector<int> top(MAXN + 1), bottom(MAXN + 1), left(MAXN + 1), right(MAXN + 1);
    for (int i = 1; i <= MAXN; i++) {
        for (int x1 = 0; x1 < i; x1++) {
            int running_sum = 0, sum = 0;
            for (int j = 0; j < MAXN; j++) {
                int elem = rect_sum(x1, j, i, j+1);
                running_sum = max(elem + running_sum, 0);
                sum = max(sum, running_sum);
            }
            top[i] = max(sum, top[i]);
        }
        for (int x2 = i + 1; x2 <= MAXN; x2++) {
            int running_sum = 0, sum = 0;
            for (int j = 0; j < MAXN; j++) {
                int elem = rect_sum(i, j, x2, j+1);
                running_sum = max(elem + running_sum, 0);
                sum = max(sum, running_sum);
            }
            bottom[i] = max(sum, bottom[i]);
        }
        for (int y1 = 0; y1 < i; y1++) {
            int running_sum = 0, sum = 0;
            for (int j = 0; j < MAXN; j++) {
                int elem = rect_sum(j, y1, j+1, i);
                running_sum = max(elem + running_sum, 0);
                sum = max(sum, running_sum);
            }
            left[i] = max(sum, left[i]);
        }
        for (int y2 = i + 1; y2 <= MAXN; y2++) {
            int running_sum = 0, sum = 0;
            for (int j = 0; j < MAXN; j++) {
                int elem = rect_sum(j, i, j+1, y2);
                running_sum = max(elem + running_sum, 0);
                sum = max(sum, running_sum);
            }
            right[i] = max(sum, right[i]);
        }
    }
    for (int i = 1; i <= MAXN; i++) {
        top[i] = max(top[i], top[i-1]);
        left[i] = max(left[i], left[i-1]);
        int rev_i = 200 - i;
        bottom[rev_i] = max(bottom[rev_i], bottom[rev_i + 1]);
        right[rev_i] = max(right[rev_i], right[rev_i + 1]);
    }
    int rem = 0;
    for (int i = 1; i <= MAXN; i++) {
        rem = max(rem, top[i] + bottom[i]);
        rem = max(rem, left[i] + right[i]);
    }

    cout << cnt + rem << endl;
    return 0;
}
