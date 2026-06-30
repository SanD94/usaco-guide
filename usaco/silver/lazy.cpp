// https://usaco.org/index.php?page=viewproblem2&cpid=416
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

int n, step;
vector<vector<int>> grass;
vector<vector<int>> diag;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

void preprocess() {
    diag.assign(2*n - 1, vector<int>(n + 1));
    for (int sm = 0; sm < 2*n - 1; sm++) {
        int i = min(sm, n - 1), j = sm - i;
        int lm = sm - i;
        while (i >= lm) {
            diag[sm][j+1] = diag[sm][j] + grass[i][j];
            i --;
            j ++;
        }
    }
}


int eval() {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cur = 0;
            int sm = i + j - step;
            int beg = j - step;
            for (int k = 0; k < step * 2 + 1; k++, sm++) {
                if (sm < 0) continue; 
                if (sm >= 2*n - 1) break;
                int sz = step + 1 - (k % 2);
                beg += k % 2;
                cur += diag[sm][min(max(beg + sz, 0), min(sm + 1, n))] - diag[sm][max(beg, 0)];
            }
            res = max(res, cur);
        }
    }
    return res;
}




int main() {
    set_io("lazy");
    cin >> n >> step;

    grass.assign(n, vector<int>(n));
    for(int i = 0; i < n; i++)
        copy_n(istream_iterator<int>(cin), n, begin(grass[i]));
    preprocess();

    cout << eval() << endl;
    return 0;
}



