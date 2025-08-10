// https://cses.fi/problemset/task/1623
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;

typedef long long int lli;

lli eval(int index, lli left, lli right, const vector<lli> &apples) {
  if (index == apples.size())
    return abs(left - right);
  return min(eval(index + 1, left + apples[index], right, apples),
             eval(index + 1, left, right + apples[index], apples));
}

lli eval(const vector<lli> &apples) { return eval(0, 0, 0, apples); }

int main() {
  int n;
  vector<lli> apples;
  cin >> n;
  copy_n(istream_iterator<lli>(cin), n, back_inserter(apples));
  cout << eval(apples) << endl;

  return 0;
}