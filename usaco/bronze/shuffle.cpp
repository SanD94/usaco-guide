// https://usaco.org/index.php?page=viewproblem2&cpid=760
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("shuffle");
  int N, ai;
  cin >> N;
  vector<int> cows(N);
  vector<int> shuffle(N);
  vector<int> order(N);
  for (int i = 0; i < N; i++) {
    cin >> ai;
    shuffle[i] = ai - 1;
  }
  copy(istream_iterator<int>(cin), istream_iterator<int>(), cows.begin());

  for (int i = 0; i < N; i++)
    cout << cows[shuffle[shuffle[shuffle[i]]]] << endl;

  return 0;
}
