// https://usaco.org/index.php?page=viewproblem2&cpid=1228
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

constexpr int MAXN{1001};

namespace std {
istream &operator>>(istream &is, pair<char, int> &p) {
  return is >> p.first >> p.second;
}

} // namespace std

int main(int argc, char const *argv[]) {
  int res = MAXN;
  int N, num;
  char c;

  cin >> N;
  vector<pair<char, int>> cows;
  copy_n(istream_iterator<pair<char, int>>(cin), N, back_inserter(cows));
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    int pick = cows[i].second;
    for (int j = 0; j < N; j++) {
      if (cows[j].first == 'G' && cows[j].second > pick)
        cnt++;
      if (cows[j].first == 'L' && cows[j].second < pick)
        cnt++;
    }
    res = min(res, cnt);
  }

  cout << res << endl;
  return 0;
}
