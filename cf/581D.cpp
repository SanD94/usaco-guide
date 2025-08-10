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

bool check(vector<point> &logos) {
  // all top
  int szx  = logos[0].x, szy = 0;
  for (int i = 0; i < 3; i++) szy += logos[i].y;
  if (szx == logos[1].x && szx == logos[2].x && szx == szy) {
    cout << szx << endl;
    for (int i = 0; i < logos.size(); i++) 
      for (int j = 0; j < logos[i].y; j ++) {
        for(int k = 0; k < logos[i].x; k++)
          cout << logos[i].c;
        cout << endl;
      }
    return true; 
  }
  szx = logos[0].x, szy = 0;
  if (
    szx == logos[1].x + logos[2].x &&
    logos[1].y == logos[2].y &&
    szx == logos[0].y + logos[1].y
  ) {
    cout << szx << endl;
    for (int i = 0; i < logos[0].y; i++) {
      for(int j = 0; j < logos[0].x; j++)
        cout << logos[0].c;
      cout << endl;
    }
    for (int i = 0; i < logos[1].y; i++) {
      for (int j = 0; j < logos[1].x; j++)
        cout << logos[1].c;
      for (int j = 0; j < logos[2].x; j++)
        cout << logos[2].c;
      cout << endl;
    }
    return true;
  }

  return false;
}





int main(int argc, char const *argv[]) {
  vector<point> logos(3);
  for (int i = 0; i < 3; i++) {
    cin >> logos[i];
    logos[i].c = 'A' + i;
  }
  sort(logos.begin(), logos.end());
  do {

    for (int i = 0; i < (1 << 3); i++) {
      for (int j = 0; j < 3; j ++)
        if (i & (1 << j)) swap(logos[j].x, logos[j].y);
      if (check(logos)) return 0;
      for (int j = 0; j < 3; j ++)
        if (i & (1 << j)) swap(logos[j].x, logos[j].y);
    }
  } while(next_permutation(logos.begin(), logos.end()));

  cout << -1 << endl;
  return 0;
}
