// https://usaco.org/index.php?page=viewproblem2&cpid=667
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
using lli = long long int;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("citystate");
  int N;
  string c, s;
  map<pair<string, string>, lli> rel;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> c >> s;
    c = c.substr(0, 2);
    if (c != s)
      rel[{c, s}]++;
  }

  lli res = 0;
  for (const auto &[p, v] : rel) {
    const auto &[c, s] = p;
    if (rel.count({s, c}))
      res += v * rel.at({s, c});
  }

  cout << res / 2 << endl;

  return 0;
}
