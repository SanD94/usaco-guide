// https://usaco.org/index.php?page=viewproblem2&cpid=891
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("shell");
  int n, a, b, g;
  array<array<bool, 4>, 4> shell{};
  array<int, 4> points{0};

  for (int i = 1; i <= 3; i++)
    shell[i][i] = true;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> g;
    for (int j = 1; j <= 3; j++) {
      shell[j][a] ^= shell[j][b];
      shell[j][b] ^= shell[j][a];
      shell[j][a] ^= shell[j][b];

      if (shell[j][g])
        points[j]++;
    }
  }

  cout << *max_element(points.begin(), points.end()) << endl;
  return 0;
}
