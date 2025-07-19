// https://usaco.org/index.php?page=viewproblem2&cpid=831
#include <iostream>
#include <map>
#include <cmath>
#include <vector>
using namespace std;


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("mowing");
  vector<vector<int>> travel(2001, vector<int>(2001));
  vector<vector<int>> dir = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
  string compass = "NESW";
  int N;
  int s, t = 1;
  int cur_x = 1000, cur_y = 1000;
  char c;
  int res = 1001;

  cin >> N;
  travel[cur_x][cur_y] = t++;
  for (int i = 0; i < N; i++) {
    cin >> c >> s;
    int index = 0;
    while(compass[index] != c) index++;
    for(int j = 0; j < s; j++) {
      cur_x += dir[index][0];
      cur_y += dir[index][1];
      int prev_t = travel[cur_x][cur_y];

      if(prev_t) res = min(res, t - prev_t);
      travel[cur_x][cur_y] = t++;
    }
    
  }
  cout << (res == 1001 ? -1 : res) << endl;

  return 0;
}
