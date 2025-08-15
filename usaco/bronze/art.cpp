// https://usaco.org/index.php?page=viewproblem2&cpid=737
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("art");
  int N;
  vector<string> painting;
  vector<bool> criminal(10, false);
  vector<bool> painted(10, false);
  cin >> N;
  copy_n(istream_iterator<string>(cin), N, back_inserter(painting));
  for (int i = 1; i <= 9; i++) {
    int x0 = N, x1 = 0, y0 = N, y1 = 0;
    for (int j = 0; j < N; j++)
      for (int k = 0; k < N; k++)
        if (painting[j][k] == i + '0') {
          x0 = min(x0, j);
          x1 = max(x1, j + 1);
          y0 = min(y0, k);
          y1 = max(y1, k + 1);
        }
    for (int j = x0; j < x1; j++)
      for (int k = y0; k < y1; k++) {
        if (painting[j][k] != i + '0') { // criminal found
          int c = painting[j][k] - '0';
          criminal[c] = true;
        }
      }
    if (x0 != N)
      painted[i] = true;
  }

  int res = 0;
  for (int i = 1; i < 10; i++)
    res += (painted[i] && !criminal[i]);

  cout << res << endl;
  return 0;
}
