// https://usaco.org/index.php?page=viewproblem2&cpid=619
#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <iterator>
using namespace std;

struct point {
  int x, y;

  friend bool operator<(const point &lhs, const point &rhs) {
    return tie(lhs.x, lhs.y) < tie(rhs.x, rhs.y);
  }

  friend istream &operator>>(istream &is, point &p) {
    return is >> p.x >> p.y;
  }
};


int N, res;
vector<point> cows;


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(int argc, char const *argv[]) {
  set_io("balancing");

  cin >> N;
  copy_n(istream_iterator<point>(cin), N, back_inserter(cows));
  
  sort(cows.begin(), cows.end());
  
  res = N;
  for(int i = 0; i < N; i++) {
    vector<point> up, down;
    int yi = cows[i].y + 1;

    for (int j = 0; j < N; j++) {
      if (cows[j].y < yi) down.emplace_back(cows[j]);
      else up.emplace_back(cows[j]);
    }

    int ul = 0, ur = up.size();
    int dl = 0, dr = down.size();

    for (int j = 0; j < N; j++) {
      int xi = cows[j].x + 1;
      while(ul < up.size() && up[ul].x < xi) { ul++; ur--; }
      while(dl < down.size() && down[dl].x < xi) { dl++; dr--; }
      res = min(res, max({ul, ur, dl, dr}));
    }
  }
  
  
  cout << res << endl;

  return 0;
}
