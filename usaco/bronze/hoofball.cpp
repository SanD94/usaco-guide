// https://usaco.org/index.php?page=viewproblem2&cpid=808
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("hoofball");
  int N;

  cin >> N;
  vector<int> locs, diff(N + 1, 2000), catcher(N, 0);
  copy_n(istream_iterator<int>(cin), N, back_inserter(locs));

  sort(all(locs));

  for (int i = 1; i < N; i++)
    diff[i] = locs[i] - locs[i - 1];
  for (int i = 0; i < N; i++) {
    catcher[i] = (diff[i] <= diff[i + 1]) ? -1 : 1;
  }
  int res = 0;
  for (int i = 0; i < N - 1; i++)
    // at least one ball is in there
    if (catcher[i] == 1 && catcher[i + 1] == -1) { // loophole
      int cnt_outside = 0;
      if (i - 1 >= 0 && catcher[i - 1] == 1)
        cnt_outside++;
      if (i + 2 < N && catcher[i + 2] == -1)
        cnt_outside++;
      res += 1 + (2 == cnt_outside);
    }

  cout << res << endl;
  return 0;
}
