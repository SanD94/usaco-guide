// https://usaco.org/index.php?page=viewproblem2&cpid=689
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
  set_io("cowtip");
  int N;

  cin >> N;
  vector<string> tips;
  vector<vector<int>> swaps(N + 1, vector<int>(N + 1, 0));

  copy_n(istream_iterator<string>(cin), N, back_inserter(tips));
  for (int i = N - 1; i >= 0; i--)
    for (int j = N - 1; j >= 0; j--) {
      int cur_swap = swaps[i + 1][j] + swaps[i][j + 1] - swaps[i + 1][j + 1];
      if (cur_swap % 2 != tips[i][j] - '0')
        cur_swap++;
      swaps[i][j] = cur_swap;
    }

  cout << swaps[0][0] << endl;
  return 0;
}
