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

  int mn_break = 0, mx_break = 0, t = -1;
  for (int i = N-1; i >= 0; i--) {
    if (t != -1 && breaks[i] != -1 && breaks[i] != t)
      corrupt = true;
    if (t == -1) t = breaks[i];
    if (breaks[i] == -1) breaks[i] = t;
    if (breaks[i] == 0) mn_break++;
    if (breaks[i] == -1) mx_break++;
    if (t > -1) t--;
  }
  if (corrupt) cout << -1 << endl;
  else cout << mn_break << " " << mn_break + mx_break << endl;
  return 0;
}
