// https://usaco.org/index.php?page=viewproblem2&cpid=1011
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

using lli = long long int;

struct point {
  lli x, y;
  
  point operator+(const point &other) const {
    return {x + other.x, y + other.y};
  }
  point operator-(const point &other) const {
    return {x - other.x, y - other.y};
  }
};

istream &operator>>(istream &is, point &p) {
  return is >> p.x >> p.y;
}

lli eval(point &a, point &b, point &c) {
  // a is the corner
  if ((b-a).x == 0 && (c-a).y == 0) return abs((b-a).y * (c-a).x);
  return 0;
}

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("triangles");
  lli res = 0, N;
  
  cin >> N;
  vector<point> fences;
  copy_n(istream_iterator<point>(cin), N, back_inserter(fences));
  
  for (int i = 0; i < N; i++)
    for(int j = 0; j < N; j++)
      for(int k = 0; k < N; k++)
        res = max(res, eval(fences[i], fences[j], fences[k]));
  cout << res << endl;
  return 0;
}
