// https://usaco.org/index.php?page=viewproblem2&cpid=617
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <cmath>
#include <numeric>
using namespace std;

int eval(vector<int> &s, int p, int q) {
  bool found = true;
  int cum = 0;
  for (int i = 0; i < s.size(); i++) {
    cum += s[i];
    if (cum == p) cum = 0;
    if (cum > p) {
      found = false;
      break;
    }
  }

  return found ? s.size() - q : s.size();
}

int main(int argc, char const *argv[]) {

  int t, N;
  cin >> t;
  while(t--) {
    cin >> N;
    vector<int> sleeps;
    copy_n(istream_iterator<int>(cin), N, back_inserter(sleeps));
    int sum = accumulate(sleeps.begin(), sleeps.end(), 0, plus<int>());


    int res = N - 1;
    if (sum == 0) {
      cout << 0 << endl;
      continue;
    }
    
    for (int i = 1; i <= (int) sqrt(sum); i ++) {
      if (sum % i == 0) {
        int k = sum / i;
        res = min(res, eval(sleeps, k, i));
        res = min(res, eval(sleeps, i, k));
      }
    }
    
    cout << res << endl;
  }

  return 0;
}
