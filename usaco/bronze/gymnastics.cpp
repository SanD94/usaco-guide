// https://usaco.org/index.php?page=viewproblem2&cpid=963
#include <array>
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAXN{10001};
int K, N;

int find_index(int x, vector<int> &gym) {
  for (int i = 0; i < N; i++)
    if (x == gym[i])
      return i;
  return -1;
}

bool is_consistent(int a, int b, vector<vector<int>> &gyms) {
  int cnta = 0, cntb = 0;
  for (int i = 0; i < K; i++) {
    int ai = find_index(a, gyms[i]);
    int bi = find_index(b, gyms[i]);
    if (ai < bi)
      cnta++;
    if (bi < ai)
      cntb++;
  }
  return (cnta > 0 && cntb == 0) || (cnta == 0 && cntb > 0);
}

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("gymnastics");
  cin >> K >> N;

  vector<vector<int>> gyms(K, vector<int>(N));
  for (int i = 0; i < K; i++)
    for (int j = 0; j < N; j++)
      cin >> gyms[i][j];

  int res = 0;
  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++)
      if (is_consistent(i, j, gyms))
        res++;

  cout << res << endl;
  return 0;
}
