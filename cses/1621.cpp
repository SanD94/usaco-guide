// https://cses.fi/problemset/task/1621
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

#define all(x) begin(x), end(x)

int main(int argc, char const *argv[]) {
  int N;
  vector<int> nums;

  cin >> N;
  copy_n(istream_iterator<int>(cin), N, back_inserter(nums));
  sort(all(nums));
  int res = unique(all(nums)) - begin(nums);
  cout << res << endl;
  return 0;
}
