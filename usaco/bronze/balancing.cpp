// https://usaco.org/index.php?page=viewproblem2&cpid=617
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

struct point {
  int x, y;
  point operator+(const point &other) const {
    return { x + other.x, y + other.y };
  }
};

istream &operator>>(istream &is, point &p) {
  return is >> p.x >> p.y;
}

int N, B, res;
vector<point> cows;

int eval(point p) {
  vector<int> cnt(4);
  for (int i = 0; i < N; i++) {
    bool x = cows[i].x < p.x;
    bool y = cows[i].y < p.y;
    int index = x + 2 * y;
    cnt[index]++;
  }
  return *max_element(cnt.begin(), cnt.end());
}

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}


int main(int argc, char const *argv[]) {
  set_io("balancing");

  cin >> N >> B;
  copy_n(istream_iterator<point>(cin), N, back_inserter(cows));
  
  res = N;
  for(int i = 0; i < N; i++) 
    for(int j = 0; j < N; j++) 
      res = min(res, eval(point{cows[i].x + 1, cows[j].y + 1}));
  
  
  cout << res << endl;

  return 0;
}
