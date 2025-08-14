// https://usaco.org/index.php?page=viewproblem2&cpid=832
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

// First sol:
// simulating the ordered ones every time is hard to debug.
// it mainly depends on pi iteration, one by one
// lots of edge cases : check fixed one and no place available
// you have to clear everything up, making debug much harder.

// Second sol:
// similar to first, go through order but jump from one to another when it's
// fixed and the current fix one should not have lower pos than current pi. If
// not fixed, find a place, behave as if it's placed. no need for correction as
// there is no assignment
bool in_order(const vector<int> &order, const vector<int> &cowp,
              const vector<int> &pcow) {
  int pi = 1;
  for (const auto cow : order) {
    if (cowp[cow]) {
      if (cowp[cow] < pi)
        return false;
      pi = cowp[cow];
      continue;
    }
    while (pi < pcow.size() && pcow[pi])
      pi++;
    if (pi == pcow.size())
      return false;
    pi++;
  }
  return true;
}

int main(int argc, char const *argv[]) {
  set_io("milkorder");
  int N, M, K, c, p, res = 0;
  bool found = false;
  cin >> N >> M >> K;

  // cow i located at p, position i cow resides
  vector<int> cowp(N + 1, 0), pcow(N + 1, 0);
  vector<int> order;

  copy_n(istream_iterator<int>(cin), M, back_inserter(order));
  for (int i = 0; i < K; i++) {
    cin >> c >> p;
    cowp[c] = p;
    pcow[p] = c;
  }
  res = cowp[1];

  for (int i = 1; i <= N && !res; i++) {
    if (pcow[i])
      continue;
    pcow[i] = 1;
    cowp[1] = i;
    if (in_order(order, cowp, pcow))
      res = i;

    pcow[i] = 0;
  }
  cout << res << endl;
  return 0;
}
