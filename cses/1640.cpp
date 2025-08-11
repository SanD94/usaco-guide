// https://cses.fi/problemset/task/1640
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  map<int, vector<int>> vals;
  int n, t, v;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> v;
    vals[v].emplace_back(i + 1);
  }

  for (const auto &[k, v] : vals)
    if (vals.count(t - k)) {
      if (t == 2 * k) {
        if (v.size() < 2)
          continue;
        cout << v[0] << " " << v[1] << endl;
        return 0;
      }
      cout << v[0] << " " << vals[t - k][0] << endl;
      return 0;
    }
  cout << "IMPOSSIBLE" << endl;

  return 0;
}
