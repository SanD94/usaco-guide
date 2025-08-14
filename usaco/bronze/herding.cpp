// https://usaco.org/index.php?page=viewproblem2&cpid=832
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("herding");
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> v{a, b, c};
  sort(all(v));
  int mn = min(v[1] - v[0], v[2] - v[1]);
  int mx = max(v[1] - v[0], v[2] - v[1]);
  int mn_res = 2, mx_res = mx - 1;
  if (mn < 2)
    mn_res = 1;
  if (mx == 1)
    mn_res = 0;

  cout << mn_res << " " << mx_res << endl;
  return 0;
}
