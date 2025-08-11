// https://usaco.org/index.php?page=viewproblem2&cpid=964
#include <iostream>
#include <set>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("whereami");
  int N, l;
  string boxes;
  set<string> seq;

  cin >> N >> boxes;
  for (int i = 0; i < N; i++) {
    l = i + 1;
    bool found = true;
    for (int j = 0; j < N - l + 1; j++) {
      string s = boxes.substr(j, l);
      if (seq.count(s)) found = false;
      seq.insert(s);
    }
    if (found)  break;
  }
  cout << l << endl;
  return 0;
}
