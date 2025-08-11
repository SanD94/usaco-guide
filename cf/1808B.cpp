// https://codeforces.com/contest/1808/problem/B
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin((x)), end((x))
using lli = long long int;

int main(int argc, char const *argv[]) {
  int t, N, M;
  cin >> t;
  while (t--) {
    cin >> N >> M;
    lli res = 0;
    vector<vector<lli>> deck(M, vector<lli>(N));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++)
        cin >> deck[j][i];
    }
    for (int i = 0; i < M; i++)
      sort(all(deck[i]));
    for (int i = 0; i < M; i++)
      for (int j = 0; j < N - 1; j++)
        res += (deck[i][j + 1] - deck[i][j]) * (j + 1) * (N - j - 1);

    cout << res << endl;
  }
  return 0;
}
