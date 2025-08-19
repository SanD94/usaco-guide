// https://usaco.org/index.php?page=viewproblem2&cpid=785
#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>
#include <vector>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("outofplace");

  int N;
  vector<int> cows;
  set<pair<int, int>> swap;

  cin >> N;
  copy_n(istream_iterator<int>(cin), N, back_inserter(cows));

  for (int i = 1; i < N; i++)
    for (int j = 0; j < i; j++)
      if (cows[i] < cows[j])
        swap.insert({cows[i], cows[j]});
  cout << swap.size() << endl;
  return 0;
}
