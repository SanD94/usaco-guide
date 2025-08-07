// https://usaco.org/index.php?page=viewproblem2&cpid=569
#include <iostream>
#include <vector>
using namespace std;


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(int argc, char const *argv[]) {
  set_io("badmilk");
  vector<vector<vector<bool>>> drink(51, 
    vector<vector<bool>>(51, 
      vector<bool>(101, false)));
  vector<int> sick(51, 0);

  
  int N, D, M, S;
  int t, m, p, s;
  cin >> N >> M >> D >> S;
  for(int i = 0; i < D; i++) {
    cin >> p >> m >> t;
    drink[m][p][t] = true;
  }
  
  for(int i = 0; i < S; i++) {
    cin >> p >> t;
    sick[p] = t;
  }
  
  int res = 0;
  for (int i = 1; i <= M; i++) {
    bool contradict = false;
    int cur_res = 0;
    for (int j = 1; j <= N; j++) {
      int drank = 0;
      for (int k = 1; k <= 100; k++)
        if (drink[i][j][k]) {
          drank = k;
          break;
        }
      if (drank && sick[j] && drank >= sick[j]) contradict = true;
      else if (!drank && sick[j]) contradict = true;
      else if (drank) cur_res++;
    }
    
    res = max(res, !contradict ? cur_res : 0);
  }
  
  cout << res << endl;
  return 0;
}
