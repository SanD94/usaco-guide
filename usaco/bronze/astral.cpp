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
    int res = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (stars[i][j] != 'W') res++;
    if (A == 0 && B == 0)
        return res;
    for(int i = N-1; i >= 0; i--)
        for (int j = N-1; j >= 0; j--) {
            int pi = i - B;
            int pj = j - A;
            if (stars[i][j] == 'W') continue;
            if (stars[i][j] == 'B') {
                if (pi < 0 || pj < 0 || stars[pi][pj] == 'W')
                    return -1;
            }
            if (stars[i][j] == 'G') {
                if (pi < 0 || pj < 0 || stars[pi][pj] == 'W')
                    continue;
                res--;
            }
            if (stars[pi][pj] == 'G') {
                stars[pi][pj] = 'W';
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



