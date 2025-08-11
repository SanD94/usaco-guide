// https://usaco.org/index.php?page=viewproblem2&cpid=1251
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin((x)), end((x))
using lli = long long int;

int main(int argc, char const *argv[]) {
  int N;
  cin >> N;
  vector<lli> cows;
  copy_n(istream_iterator<lli>(cin), N, back_inserter(cows));
  sort(all(cows));
  lli res = 0, tuit;
  for (int i = 0; i < N; i++) {
    lli cur_money = (N - i) * cows[i];
    if (cur_money > res) {
      res = cur_money;
      tuit = cows[i];
    }
  }
  cout << res << " " << tuit << endl;

  return 0;
}
