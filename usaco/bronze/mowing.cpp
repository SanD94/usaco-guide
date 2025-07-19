// https://usaco.org/index.php?page=viewproblem2&cpid=831
#include <iostream>
#include <map>
#include <cmath>
using namespace std;


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("mowing");
  map<pair<int,int>,int> travel;
  int dir[4][2] = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
  string compass = "NESW";
  int N;
  int s, t = 1;
  int cur_x = 0, cur_y = 0;
  char c;
  unsigned int res = UINT32_MAX;

  cin >> N;
  travel[{0, 0}] = t++;
  for (int i = 0; i < N; i++) {
    cin >> c >> s;
    int index = 0;
    while(compass[index] != c) index++;
    for(int j = 0; j < s; j++) {
      cur_x += dir[index][0];
      cur_y += dir[index][1];
      int prev_t = travel[{cur_x, cur_y}];

      if(prev_t) res = min(res, (unsigned int) t - prev_t);
      travel[{cur_x, cur_y}] = t++;
    }
    
  }
  cout << (int) res << endl;

  return 0;
}
