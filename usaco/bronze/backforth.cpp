// https://usaco.org/index.php?page=viewproblem2&cpid=857
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

vector<bool> mark(2001, false);

void backforth(int visit, int cur_val, vector<int> &buckets,
               vector<int> &barn) {
  if (visit == 4) {
    mark[cur_val] = true;
    return;
  }
  for (int i = 0; i < 20; i++) {
    if (barn[i] == visit % 2) {
      barn[i] = !barn[i];
      cur_val += buckets[i] * (visit % 2 ? 1 : -1);
      backforth(visit + 1, cur_val, buckets, barn);
      barn[i] = !barn[i];
      cur_val -= buckets[i] * (visit % 2 ? 1 : -1);
    }
  }
}

void backforth(vector<int> &buckets, vector<int> &barn) {
  backforth(0, 1000, buckets, barn);
}

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("backforth");
  mark[1000] = true; // 1000 is the initial state

  vector<int> buckets;
  vector<int> barn(20);
  copy_n(istream_iterator<int>(cin), 20, back_inserter(buckets));

  fill(barn.begin(), barn.begin() + 10, 0);
  fill(barn.begin() + 10, barn.end(), 1);

  backforth(buckets, barn);

  int res = 0;
  for (int i = 0; i < mark.size(); i++)
    if (mark[i])
      res++;

  cout << res << endl;
  return 0;
}
