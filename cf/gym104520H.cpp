// https://codeforces.com/gym/104520/problem/H
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin((x)), end((x))
#define rall(x) rbegin((x)), rend((x))
using lli = long long int;

int main(int argc, char const *argv[]) {

  int N;
  lli res = 0;
  cin >> N;
  vector<lli> a, b;
  copy_n(istream_iterator<lli>(cin), N, back_inserter(a));
  copy_n(istream_iterator<lli>(cin), N, back_inserter(b));
  for (int i = 0; i < N; i++)
    a[i] = a[i] * (i + 1) * (N - i);
  sort(all(a));
  sort(rall(b));
  for (int i = 0; i < N; i++)
    res += a[i] * b[i];

  cout << res << endl;
  return 0;
}
