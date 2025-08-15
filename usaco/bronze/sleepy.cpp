// https://usaco.org/index.php?page=viewproblem2&cpid=892
#include <algorithm>
#include <iterator>
#include <iostream>
#include <vector>
using namespace std;

#define all(x) begin(x), end(x)

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("sleepy");
  int N;
  vector<int> cows;
  cin >> N;
  copy_n(istream_iterator<int>(cin), N, back_inserter(cows));
  int ex = 1;
  for (int i = 0; i < N - 1; i++) {
    ex++;
    if (cows[i] > cows[i+1]) ex = 1;
  }
  cout << N - ex << endl;
  return 0;
}
