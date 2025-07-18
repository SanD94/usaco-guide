// https://usaco.org/index.php?page=viewproblem2&cpid=917
#include <iostream>
#include <iterator>
#include <tuple>
#include <vector>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("traffic");
  int N;
  string type;
  int start, end;
  cin >> N;
  vector<tuple<string, int, int>> flow;
  for (int i = 0; i < N; i++) {
    cin >> type >> start >> end;
    flow.emplace_back(type, start, end);
  }

  int s = 0, e = 1000;
  for (int i = N - 1; i >= 0; i--) {
    auto [pos, start, end] = flow[i];

    if (pos == "on") {
      s = max(s - end, 0);
      e = e - start;
    } else if (pos == "off") {
      s = s + start;
      e = min(e + end, 1000);
    } else {
      s = max(s, start);
      e = min(e, end);
    }
  }
  cout << s << " " << e << endl;
  for (int i = 0; i < N; i++) {
    auto [pos, start, end] = flow[i];

    if (pos == "on") {
      s = s + start;
      e = min(e + end, 1000);
    } else if (pos == "off") {
      s = max(s - end, 0);
      e = e - start;
    } else {
      s = max(s, start);
      e = min(e, end);
    }
  }
  cout << s << " " << e << endl;
  return 0;
}
