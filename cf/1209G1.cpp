// https://codeforces.com/contest/1209/problem/G1
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <tuple>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

int main(int argc, char const *argv[]) {
  int n, q, a;
  map<int, tuple<int, int, int>> iv;

  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a;
    int b = i, e = i;
    if (!iv.count(a))
      iv[a] = {b, e, 1};
    else {
      auto [b, e, c] = iv[a];
      iv[a] = {b, i, c + 1};
    }
  }

  vector<tuple<int, int, int>> ivv;
  transform(all(iv), back_inserter(ivv),
            [](const pair<int, tuple<int, int, int>> &p) { return p.second; });

  sort(all(ivv));
  int res = 0;
  for (int i = 0; i < ivv.size();) {
    auto [b, e, c] = ivv[i++];
    int cur_max = c;
    while (i < ivv.size() && get<0>(ivv[i]) < e) {
      e = max(e, get<1>(ivv[i]));
      cur_max = max(cur_max, get<2>(ivv[i++]));
    }
    res += e - b + 1 - cur_max;
  }
  cout << res << endl;
  return 0;
}
