// https://usaco.org/index.php?page=viewproblem2&cpid=784
#include <iostream>
#include <vector>
using namespace std;


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("lifeguards");
  
  int N, s, e;
  cin >> N;
  vector<int> times(1000, 0);
  vector<pair<int, int>> guards;
  for (int i = 0; i < N; i++) {
    cin >> s >> e;
    guards.emplace_back(s, e);
    for(int j = s; j < e; j++) times[j]++;
  }
  
  int res = 0;
  for (int i = 0; i < N; i++) {
    for(int j = guards[i].first; j < guards[i].second; j++)
      times[j]--;
    int cnt = 0;
    for(int j = 0; j < 1000; j++) if (times[j]) cnt++;
    for(int j = guards[i].first; j < guards[i].second; j++)
      times[j]++;
    res = max(res, cnt);
  }
  cout << res << endl;

  return 0;
}
