// https://cses.fi/problemset/task/1624
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool eval(vector<int> &queens, vector<vector<bool>> &mark) {
  int x, y, ix, iy;
  for (int i = 0; i < 8; i++) {
    x = i, y = queens[i];
    if (mark[x][y]) return false;
    // left diag
    ix = x - min(x, y) - 1, iy = y - min(x, y) - 1;
    while (ix++ < 7 && iy++ < 7) {
      if (ix == x && iy == y) continue;
      if (queens[ix] == iy) return false;
    }
    // right diag
    ix = x - min(x, 7 - y) - 1, iy = y + min(x, 7 - y) + 1;
    while (ix++ < 7 && iy-- > 0) {
      if (ix == x && iy == y) continue;
      if (queens[ix] == iy) return false;
    }
    
  }
  return true;
}

int main(int argc, char const *argv[]) {
  vector<vector<bool>> reserved(8, vector<bool>(8, false));
  vector<int> placed;
  string s;

  for (int i = 0; i < 8; i++) {
    cin >> s;
    placed.emplace_back(i);
    for (int j = 0; j < 8; j++) reserved[i][j] = s[j] == '*';
  }
  
  int res = 0;
  do {
    res += eval(placed, reserved);
  } while(next_permutation(placed.begin(), placed.end()));
  
  cout << res << endl;
  return 0;
}
