// https://usaco.org/index.php?page=viewproblem2&cpid=1227
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int N, res = 0, cur = 3;
  string s;

  cin >> N;
  cin >> s;
  
  
  for (int i = 0; i < N / 2; i++) {
    int next = 2;
    // "GH" -> 0 "HG" -> 1
    if (s[2*i] == 'G' && s[2*i + 1] == 'H') next = 0;
    if (s[2*i] == 'H' && s[2*i + 1] == 'G') next = 1;
    if (next < 2 && (cur ^ next)) {
      res ++;
      cur = next;
    }
  }
  
  if (res && cur) res--;
  cout << res << endl;

  return 0;
}
