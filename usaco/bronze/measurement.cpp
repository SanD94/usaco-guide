// https://usaco.org/index.php?page=viewproblem2&cpid=831
#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int find_index(string name, array<string, 3> &names) {
  for (int i = 0; i < names.size(); i++)
    if (name == names[i]) return i;
  return -1;
}

int display(array<int, 3> &cows) {
  int mx = *max_element(cows.begin(), cows.end());
  int k = 0;
  for (auto cow : cows) {
    k <<= 1;
    k |= (cow == mx);
  }
  return k;
}

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("measurement");
  int N, t, m;
  string name;

  int panel = 7;
  array<int, 3> cows{7,7,7};
  array<int, 101> ms;
  array<string, 101> ms_names{};
  array<string, 3> names{"Bessie", "Elsie", "Mildred"};
  cin >> N;
  
  for(int i = 0; i < N; i++) {
    cin >> t >> name >> m;
    ms_names[t] = name;
    ms[t] = m;
  }

  int cnt = 0;
  for (int i = 1; i <= 100; i++) {
    if (ms[i]) {
      int j = find_index(ms_names[i], names);
      cows[j] += ms[i];
      int cur_panel = display(cows);
      if (panel ^ cur_panel) cnt ++;
      panel = cur_panel;
    }
  }
  cout << cnt << endl;
  return 0;
}
