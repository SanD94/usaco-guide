// https://usaco.org/index.php?page=viewproblem2&cpid=592
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

#define all(x) begin((x)), end((x))

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("angry");
  int N;
  cin >> N;
  vector<int> bales;
  copy_n(istream_iterator<int>(cin), N, back_inserter(bales));
  sort(all(bales));
  int res = 0;
  for (int i = 0; i < N; i++) {
    vector<int> exp(N, 0);
    exp[i] = 1;
    vector<int> ex_bales;
    ex_bales.emplace_back(i);
    while (!ex_bales.empty()) {
      int cur_bale = ex_bales.back();
      ex_bales.pop_back();
      int r = exp[cur_bale];
      int pos = bales[cur_bale];
      int lbale = cur_bale - 1, rbale = cur_bale + 1;
      // left
      while (lbale >= 0 && bales[lbale] >= pos - r) {
        if (!exp[lbale]) {
          exp[lbale] = r + 1;
          ex_bales.emplace_back(lbale);
        }
        lbale--;
      }
      while (rbale < N && bales[rbale] <= pos + r) {
        if (!exp[rbale]) {
          exp[rbale] = r + 1;
          ex_bales.emplace_back(rbale);
        }
        rbale++;
      }
    }

    int cur_res = 0;
    for (int j = 0; j < N; j++)
      if (exp[j])
        cur_res++;
    res = max(res, cur_res);
  }
  cout << res << endl;

  return 0;
}
