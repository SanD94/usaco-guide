// https://usaco.org/index.php?page=viewproblem2&cpid=1012
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("breedflip");
  int N;
  string A, B;
  cin >> N;
  cin >> A >> B;
  
  int res = 0;
  for (int i = 0; i < A.length(); i++) {
      bool found = false;
      while (i < A.length() && A[i] != B[i]) { found = true; i++; }
      if (found) {
        res ++;
        i --;
      }
  }
  cout << res << endl;
  return 0;
}
