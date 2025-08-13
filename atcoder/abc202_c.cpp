// https://atcoder.jp/contests/abc202/tasks/abc202_c?lang=en
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using lli = long long int;

int main(int argc, char const *argv[]) {
  int N, a;
  cin >> N;
  vector<lli> cntA(N + 1), cntB(N + 1);
  vector<int> B;
  for (int i = 0; i < N; i++) {
    cin >> a;
    cntA[a]++;
  }
  copy_n(istream_iterator<int>(cin), N, back_inserter(B));
  for (int i = 0; i < N; i++) {
    cin >> a;
    cntB[B[a - 1]]++;
  }

  lli res = 0;
  for (int i = 1; i <= N; i++)
    res += cntA[i] * cntB[i];

  cout << res << endl;

  return 0;
}
