// https://usaco.org/index.php?page=viewproblem2&cpid=1059
#include <array>
#include <iostream>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("speeding");
  array<int, 100> speed_limit{};
  array<int, 100> speed{};
  int n, m, mile, s, road = 0;

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> mile >> s;
    for (int j = 0; j < mile; j++)
      speed_limit[j + road] = s;
    road += mile;
  }

  road = 0;
  for (int i = 0; i < m; i++) {
    cin >> mile >> s;
    for (int j = 0; j < mile; j++)
      speed[j + road] = s;
    road += mile;
  }

  int res = 0;
  for (int i = 0; i < 100; i++)
    res = max(res, speed[i] - speed_limit[i]);

  cout << res << endl;
  return 0;
}
