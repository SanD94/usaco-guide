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
  vector<int> out(101, 0);
  cin >> N;
  int a, b;
  for (int i = 0; i < N - 1; i++) {
    cin >> a >> b;
    out[a]++;
  }
  vector<int> res;
  for (int i = 1; i <= N; i++) {
    if (out[i] == 0)
      res.emplace_back(i);
  }
  int idx = res.size() == 1 ? res[0] : -1;

  cout << idx << endl;
  return 0;
}
