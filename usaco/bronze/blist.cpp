// https://usaco.org/index.php?page=viewproblem2&cpid=760
#include <array>
#include <iostream>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("blist");

  int N, s, t, b, res = 0, cur_buckets = 0;
  array<int, 1001> buckets{0};

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s >> t >> b;
    buckets[s] = b;
    buckets[t] = -b;
  }
  for (int i = 1; i < 1001; i++) {
    cur_buckets += buckets[i];
    res = max(res, cur_buckets);
  }

  cout << res << endl;

  return 0;
}
