// https://usaco.org/index.php?page=viewproblem2&cpid=831
#include <iostream>
using namespace std;


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("censor");
  
  string S, T;
  cin >> S >> T;
  string res = "";
  for (char c : S) {
    res += c;
    if (res.size() >= T.size() && res.substr(res.size() - T.size()) == T) 
      res.resize(res.size() - T.size());
  }
  cout << res << endl;
  return 0;
}
