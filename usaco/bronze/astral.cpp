// https://usaco.org/index.php?page=viewproblem2&cpid=1467
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


int T;
int N, A, B;
vector<string> stars;

int eval(vector<string> &stars) {
    vector<vector<bool>> has_star(N, vector<bool>(N));
    int res = 0;

    auto add_star = [&](int i, int j) {
        if (!has_star[i][j]) {
            has_star[i][j] = true;
            res++;
        }
    };

    for (int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) {
            int pi = i - B;
            int pj = j - A;
            bool is_allowed = 0 <= pi && 0 <= pj;
            if (stars[i][j] == 'B') {
                if (!is_allowed || stars[pi][pj] == 'W') return -1;
                add_star(i, j);
                add_star(pi, pj);
            }
            if (stars[i][j] == 'G') {
                if (is_allowed && has_star[pi][pj]) continue;
                add_star(i,j);
            }
        }
    return res;
}




int main(int argc, char const *argv[]) {
    cin >> T;
    while (T--) {
        stars.resize(0);
        cin >> N >> A >> B;
        copy_n(istream_iterator<string>(cin), N, back_inserter(stars));
        cout << eval(stars) << endl;
    }
    return 0;

}



