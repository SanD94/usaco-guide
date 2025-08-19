// https://usaco.org/index.php?page=viewproblem2&cpid=785
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
  set_io("outofplace");

  int N, res = 0;
  vector<int> cows;

  cin >> N;
  copy_n(istream_iterator<int>(cin), N, back_inserter(cows));
  vector<int> sorted(cows);
  sort(all(sorted));

  for (int i = 0; i < N; i++)
    if (sorted[i] != cows[i])
      res++;

  cout << res - 1 << endl;
  return 0;
}
