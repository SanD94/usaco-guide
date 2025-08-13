// https://usaco.org/index.php?page=viewproblem2&cpid=687
#include <iostream>
#include <map>
#include <queue>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("notlast");
  int N;
  map<string, int> milking {
    {"Bessie", 0}, {"Elsie", 0}, {"Daisy", 0}, {"Gertie", 0}, 
    {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0}
  };
  string cow;
  int m;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> cow >> m;
    milking[cow] += m;
  }
  priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> Q;
  for (const auto &[k, v] : milking) 
    Q.emplace(v, k);
  int mn = Q.top().first;
  Q.pop();
  while (!Q.empty() && Q.top().first == mn) Q.pop();
  if (!Q.empty()) {
    auto [res, elem] = Q.top(); Q.pop();
    if (!(!Q.empty() && Q.top().first == res)) {
      cout << elem << endl;
      return 0;
    }
  }
  cout << "Tie" << endl;
  return 0;
}
