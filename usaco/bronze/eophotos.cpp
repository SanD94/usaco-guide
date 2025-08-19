// https://usaco.org/index.php?page=viewproblem2&cpid=1084
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  int N, even = 0, odd = 0, cid, res = 0;
  bool turn = true;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> cid;
    (cid % 2) ? odd++ : even++;
  }

  while (odd && even) {
    turn ? even-- : odd--;
    turn = !turn;
    res++;
  }
  res += odd / 3 * 2;
  if (!turn && odd % 3 == 1)
    res++;
  if (turn) {
    if (odd % 3 == 1)
      res--;
    if (odd % 3 == 2)
      res++;
    if (even)
      res++;
  }

  cout << res << endl;

  return 0;
}
