// https://usaco.org/index.php?page=viewproblem2&cpid=1037
#include <iostream>
#include <vector>
#include <string>
using namespace std;


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


struct interaction {
  size_t x, y;
};

istream &operator>>(istream &is, interaction &i) {
  return is >> i.x >> i.y;
}


int main(int argc, char const *argv[]) {
  set_io("tracing");
  size_t N, T, t, a, b;
  string end_res; 
  size_t x = 0, y = 1000, z = 0;
  vector<interaction> vals(251);
  vector<bool> mark(251, false);

  cin >> N >> T;
  cin >> end_res;

  for (int i = 0; i < T; i++) {
    cin >> t >> a >> b;
    vals[t] = {a, b};
    mark[t] = true;
  }
  
  for (int i = 1; i <= N; i++) { // pick cow 
    bool gross_found = false;
    for (int j = 0; j <= 251; j ++) { // pick K
      bool found = false;
      string sim(N, '0');
      vector<int> sick(N + 1, j);
      sim[i-1] = '1';
      for (int k = 1; k <= 250; k++) { // time pass
        if (mark[k]) {
          auto [s, e] = vals[k];
          bool s_sick = sick[s] && sim[s-1] == '1';
          bool e_sick = sick[e] && sim[e-1] == '1';
          if (s_sick) {
            sick[s]--;
            sim[e-1] = '1';
          }
          if (e_sick) {
            sick[e] --;
            sim[s-1] = '1';
          }
        }
      }
      if (sim == end_res) {
        found = true;
        y = min(y, (size_t)j);
        z = max(z, (size_t)j);
      }
      gross_found |= found;
    }
    if (gross_found) x ++;
  }
  
  cout << x << " " << y << " " << (z == 251 ? "Infinity" : to_string(z)) << endl;
  
  return 0;
}
