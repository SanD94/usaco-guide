// https://codeforces.com/contest/831/problem/C
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, k, a;
  cin >> n >> k;
  vector<int> points(n + 1, 0);
  vector<int> guess;

  for (int i = 1; i <= n; i++) {
    cin >> a;
    points[i] = points[i - 1] - a;
  }
  copy_n(istream_iterator<int>(cin), k, back_inserter(guess));
  set<int> pos_vals;
  for (int i = 1; i <= n; i++)
    pos_vals.insert(guess[0] + points[i]);

  for (int i = 1; i < k; i++) {
    set<int> next_pos_vals;
    for (int j = 1; j <= n; j++)
      if (pos_vals.count(guess[i] + points[j]))
        next_pos_vals.insert(guess[i] + points[j]);
    pos_vals = next_pos_vals;
  }

  cout << pos_vals.size() << endl;

  return 0;
}
