// https://usaco.org/index.php?page=viewproblem2&cpid=989
#include <iostream>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int eval(int run, int lim) {
  int t = 0, cur_run = 0, tot_t = 0;
  while (true) {
    t ++;
    tot_t ++;
    cur_run += t;
    if (cur_run >= run) return tot_t;
    if (t >= lim) {
      cur_run += t;
      tot_t++;
      if (cur_run >= run) return tot_t;
    }
  }
  return -1;

}

int main(int argc, char const *argv[]) {
  set_io("race");
  int K, N, X;
  cin >> K >> N;
  for (int i = 0; i < N; i++) {
    cin >> X;
    cout << eval(K, X) << endl;
  }

  return 0;
}
