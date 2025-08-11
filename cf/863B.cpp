// https://codeforces.com/contest/863/problem/B
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin((x)), end((x))
using lli = long long int;

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<int> kayak;
  copy_n(istream_iterator<int>(cin), 2 * n, back_inserter(kayak));
  sort(all(kayak));
  vector<bool> single(2 * n, false);
  int res = 1e8;
  for (int i = 0; i < 2 * n; i++) {
    for (int j = i + 1; j < 2 * n; j++) {
      single[i] = single[j] = true;
      int cur_res = 0;
      for (int k = 0, sign = -1; k < 2 * n; k++) {
        if (single[k])
          continue;
        cur_res += kayak[k] * sign;
        sign *= -1;
      }
      res = min(res, cur_res);
      single[i] = single[j] = false;
    }
  }
  cout << res << endl;
  return 0;
}
