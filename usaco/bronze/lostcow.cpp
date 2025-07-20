// https://usaco.org/index.php?page=viewproblem2&cpid=735
#include <array>
#include <iostream>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("lostcow");
  int x, y;
  cin >> x >> y;
  int res = 0, dir = 1, cur_loc = x, step = 1;
  int cur_lim = x + dir * step;

  while (cur_loc != y) {
    cur_loc += dir;
    res++;
    if (cur_loc == cur_lim) {
      step <<= 1;
      dir *= -1;
      cur_lim = x + dir * step;
    }
  }
  cout << res << endl;
}
