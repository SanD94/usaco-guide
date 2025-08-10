// https://cses.fi/problemset/task/1622
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

typedef long long int lli;

int main() {
  string s;
  vector<string> res;
  cin >> s;
  sort(s.begin(), s.end());
  do {
    res.emplace_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << res.size() << endl;
  copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));

  return 0;
}
