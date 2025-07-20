// https://usaco.org/index.php?page=viewproblem2&cpid=616
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("cbarn");
  int N;
  vector<int> rooms;

  cin >> N;
  copy(istream_iterator<int>(cin), istream_iterator<int>(),
       back_inserter(rooms));

  int res = __INT32_MAX__;
  for (int i = 0; i < N; i++) {
    int sum = 0;
    for (int j = 0; j < N; j++)
      sum += j * rooms[(i + j) % N];

    res = min(res, sum);
  }
  cout << res << endl;

  return 0;
}
