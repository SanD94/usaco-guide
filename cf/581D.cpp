// https://codeforces.com/problemset/problem/581/D
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

struct point {
  int x, y;
  char c;
  
  friend bool operator<(const point &lhs, const point &rhs) {
    return lhs.c < rhs.c;
  }
  
  friend istream &operator>>(istream &is, point &p) {
    return is >> p.x >> p.y;
  }
};


bool found = false;

void print(vector<point> &ps, vector<point> logos, int sz) {
  if (found) return;
  vector<vector<char>> board(sz, vector<char>(sz));
  for (const auto &p : ps) 
    if (p.c != 0) {
      int lx, ly;
      char c;
      if (p.c > 3) lx = logos[p.c - 4].y, ly = logos[p.c - 4].x, c = logos[p.c - 4].c;
      else lx = logos[p.c - 1].x, ly = logos[p.c - 1].y, c = logos[p.c - 1].c;
      for (int i = p.x; i < p.x + lx; i++)
        for(int j = p.y; j < p.y + ly; j++)
          board[j][i] = c;
    }
  cout << sz << endl;
  for (int i = 0; i < sz; i++) {
    for(int j = 0; j < sz; j++) cout << board[i][j];
    cout << endl;
  }
  found = true;
}

void place(vector<point> ps, int idx, vector<point> logos) {
  if (idx == 3) {
    
    int tx = 0, ty = 0;
    vector<vector<int>> mark(301, vector<int>(301, 0));
    for (const auto &p : ps) 
      if (p.c != 0) {
        int lx, ly;
        if (p.c > 3) lx = logos[p.c - 4].y, ly = logos[p.c - 4].x;
        else lx = logos[p.c - 1].x, ly = logos[p.c - 1].y;
        for (int i = p.x; i < p.x + lx; i++)
          for(int j = p.y; j < p.y + ly; j++)
            mark[i][j]++;
        tx = max(tx, p.x + lx);
        ty = max(ty, p.y + ly);
      }
    bool is_found = true;
    if (tx != ty) is_found = false;
    for(int i = 0; i < tx; i++)
      for(int j = 0; j < ty; j++)
        if (mark[i][j] != 1) is_found = false;
    
    if (is_found) print(ps, logos, tx);
    return;
  }
  if (found) return;
  int tx, ty;
  for (int i = 0; i < ps.size(); i++) {
    if (ps[i].c == 0) {
      // normal
      ps[i].c = logos[idx].c - 'A' + 1;
      tx = ps[i].x + logos[idx].x;
      ty = ps[i].y + logos[idx].y;
      ps.push_back({tx, ps[i].y, 0});
      ps.push_back({ps[i].x, ty, 0});
      place(ps, idx + 1, logos);
      ps.pop_back(); ps.pop_back();
      ps[i].c = 0;
      // t
      ps[i].c = logos[idx].c - 'A' + 4;
      tx = ps[i].x + logos[idx].y;
      ty = ps[i].y + logos[idx].x;
      ps.push_back({tx, ps[i].y, 0});
      ps.push_back({ps[i].x, ty, 0});
      place(ps, idx + 1, logos);
      ps.pop_back(); ps.pop_back();
      ps[i].c = 0;
    }
  }
}

bool check(vector<point> &logos) {
  place(vector<point>{{0, 0, 0}}, 0, logos);
  return found;
}

int main(int argc, char const *argv[]) {
  vector<point> logos(3);
  for (int i = 0; i < 3; i++) {
    cin >> logos[i];
    logos[i].c = 'A' + i;
  }
  sort(logos.begin(), logos.end());
  do {
    if (check(logos)) return 0;
  } while(next_permutation(logos.begin(), logos.end()));

  cout << -1 << endl;
  return 0;
}
