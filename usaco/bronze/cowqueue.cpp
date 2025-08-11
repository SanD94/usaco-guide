// https://usaco.org/index.php?page=viewproblem2&cpid=713
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin((x)), end((x))

struct cow {
  int arrive, q;
  friend bool operator<(const cow &lhs, const cow &rhs) {
    return lhs.arrive < rhs.arrive;
  }
  friend istream &operator>>(istream &is, cow &c) {
    return is >> c.arrive >> c.q;
  }
};

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("cowqueue");
  int N;
  cin >> N;
  vector<cow> cows;
  copy_n(istream_iterator<cow>(cin), N, back_inserter(cows));
  sort(all(cows));
  int t = 0;
  for (const auto &c : cows) {
    t = max(t, c.arrive);
    t += c.q;
  }
  cout << t << endl;

  return 0;
}
