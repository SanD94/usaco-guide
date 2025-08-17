// https://usaco.org/index.php?page=viewproblem2&cpid=1012
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

using lli = long long int;


int main(int argc, char const *argv[]) {
  int N, K;
  cin >> N >> K;
  lli res = 0, t0, t1;

  cin >> t1;
  res += K + 1;
  t0 = t1;

  for (int i = 0; i < N - 1; i++)  {
    cin >> t1;
    res += (t0 + K < t1) ? (1 + K) : (t1 - t0); // new sub or continue
    t0 = t1;
  }
  
  cout << res << endl;
  
  return 0;
}
