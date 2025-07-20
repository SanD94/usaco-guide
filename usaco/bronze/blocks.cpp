// https://usaco.org/index.php?page=viewproblem2&cpid=664
#include <array>
#include <iostream>
#include <iterator>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("blocks");
  int N;
  string s1, s2;
  array<int, 26> res{};

  cin >> N;
  for (int i = 0; i < N; i++) {
    array<int, 26> s1c{};
    array<int, 26> s2c{};
    cin >> s1 >> s2;
    for (char c : s1)
      s1c[c - 'a']++;
    for (char c : s2)
      s2c[c - 'a']++;
    for (int j = 0; j < 26; j++)
      res[j] += max(s1c[j], s2c[j]);
  }

  copy(res.begin(), res.end(), ostream_iterator<int>(cout, "\n"));

  return 0;
}
