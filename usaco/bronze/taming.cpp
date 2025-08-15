// https://usaco.org/index.php?page=viewproblem2&cpid=809
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("taming");
  int N;
  bool corrupt = false;
  vector<int> breaks;
  cin >> N;
  copy_n(istream_iterator<int>(cin), N, back_inserter(breaks));
  if (breaks[0] > 0) corrupt = true;
  breaks[0] = 0;

  int mn_break = 0, mx_break = 0;
  for (int i = 0; i < N; i++) {
    if (breaks[i] > 0) {
      if (i - breaks[i] < 0) corrupt = true;
      else {
        for (int j = 0; j <= breaks[i]; j++) {
          // -1 -1 2 -1 4
          if (breaks[i-j] == -1 || breaks[i-j] == breaks[i] - j)
            breaks[i - j] = breaks[i] - j;
          else corrupt = true;
        }
      }
    }
  }
  for(int i = 0; i < N; i++) {
    if (breaks[i] == 0) mn_break++;
    if (breaks[i] == -1) mx_break++;
  }
  if (corrupt) cout << -1 << endl;
  else cout << mn_break << " " << mn_break + mx_break << endl;
  return 0;
}
