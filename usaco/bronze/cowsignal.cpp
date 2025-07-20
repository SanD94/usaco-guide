// https://usaco.org/index.php?page=viewproblem2&cpid=665
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("cowsignal");
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> signal(n);

  copy(istream_iterator<string>(cin), istream_iterator<string>(),
       signal.begin());

  for (int i = 0; i < n * k; i++) {
    for (int j = 0; j < m * k; j++)
      cout << signal[i / k][j / k];

    cout << endl;
  }

  return 0;
}
