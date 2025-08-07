// https://usaco.org/index.php?page=viewproblem2&cpid=736
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int N, M;
string codes = "ATGC";

int find_index(char ch) {
  for (int i = 0; i < 4; i++)
    if (codes[i] == ch)
      return i;
  return -1;
}

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("cownomics");
  int res = 0;
  cin >> N >> M;

  vector<string> spots;
  vector<string> nomics;

  copy_n(istream_iterator<string>(cin), N, back_inserter(spots));
  copy_n(istream_iterator<string>(cin), N, back_inserter(nomics));

  for (int i = 0; i < M; i++) {
    vector<int> scount(4);
    vector<int> ncount(4);
    for (int j = 0; j < N; j++)
      scount[find_index(spots[j][i])]++;
    for (int j = 0; j < N; j++)
      ncount[find_index(nomics[j][i])]++;
    bool nonconsistent = false;
    for (int j = 0; j < 4; j++)
      nonconsistent |= scount[j] > 0 && ncount[j] > 0;

    if (!nonconsistent)
      res++;
  }

  cout << res << endl;
  return 0;
}
