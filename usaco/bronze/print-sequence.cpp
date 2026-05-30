// https://usaco.org/index.php?page=viewproblem2&cpid=1493
#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
using namespace std;

int N, T, K;
vector<int> target;
vector<string> vals = { "NO", "YES" };

bool go(int N, int K) {
    const int INF = 101;
    vector<vector<int>> same_prefix(N + 1, vector<int>(N + 1));
    vector<vector<int>> min_prints(N, vector<int>(N, INF));

    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (target[i] == target[j]) {
                same_prefix[i][j] = same_prefix[i + 1][j + 1] + 1;
            }
        }
    }

    for (int len = 1; len <= N; len++) {
        for (int b = 0; b + len <= N; b++) {
            int e = b + len - 1;

            if (len == 1) {
                min_prints[b][e] = 1;
                continue;
            }

            for (int mid = b; mid < e; mid++) {
                min_prints[b][e] = min(min_prints[b][e],
                                       min_prints[b][mid] + min_prints[mid + 1][e]);
            }

            for (int block_len = 1; block_len < len; block_len++) {
                if (len % block_len == 0 && same_prefix[b][b + block_len] >= len - block_len) {
                    min_prints[b][e] = min(min_prints[b][e], min_prints[b][b + block_len - 1]);
                }
            }
        }
    }

    return min_prints[0][N - 1] <= K;
}


int main(int argc, char const *argv[]) {
    cin >> T;
    while (T--) {
        target.resize(0);
        cin >> N >> K;
        copy_n(istream_iterator<int>(cin), N, back_inserter(target));
        cout << vals[go(N, K)] << endl;
    }

    return 0;
}
