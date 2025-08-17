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
  lli a, res = 0, t0, t1;

  cin >> a;
  res += K;
  t0 = t1 = a;

  for (int i = 0; i < N - 1; i++)  {
    cin >> a;
    if (t1 + K < a) { // finish old and start new sub
      res += (t1 - t0) + 1 + K;
      t0 = a;
    }
    t1 = a;
  }
  res += (t1 - t0) + 1;
  
  cout << res << endl;
  
  return 0;
}
