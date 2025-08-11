// https://cses.fi/problemset/task/1640
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[]) {
  map<int, int> vals;
  int n, t, k;
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> k;
    if (vals.count(t - k)) {
      cout << vals[t - k] << " " << i + 1 << endl;
      return 0;
    }
    vals[k] = i + 1;
  }

  cout << "IMPOSSIBLE" << endl;

  return 0;
}
