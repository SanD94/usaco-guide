// https://usaco.org/index.php?page=viewproblem2&cpid=940
#include <iostream>
#include <vector>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("factory");
  int N;
  vector<int> child(101, -1);
  vector<int> cnt(101, 0);
  cin >> N;
  int a, b;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    child[a] = b;
  }
  for (int i = 1; i <= N; i++) {
    int cur = i;
    while (child[cur] != -1)
      cur = child[cur];
    cnt[cur]++;
  }

  int res = -1;
  for (int i = 1; i <= N; i++)
    if (cnt[i] == N)
      res = i;
  cout << res << endl;
  return 0;
}
