// https://judge.yosupo.jp/problem/associative_array
#include <iostream>
#include <map>
using namespace std;

using lli = long long int;

int main(int argc, char const *argv[]) {
  int Q, a;
  lli k, v;
  map<lli, lli> m;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    cin >> a;
    if (a == 0) {
      cin >> k >> v;
      m[k] = v;
    }
    if (a == 1) {
      cin >> k;
      cout << m[k] << endl;
    }
  }
  return 0;
}
