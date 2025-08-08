// https://usaco.org/index.php?page=viewproblem2&cpid=1276
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct ac {
  int s, t, p, m;
};

bool is_relaxed(vector<ac> &acs, vector<int> &barns, vector<int> &used) {
  bool relaxed = true;
  for (auto &u : used)
    for (int i = acs[u].s; i <= acs[u].t; i++)
      barns[i] -= acs[u].p;

  for (const auto &b : barns)
    if (b > 0)
      relaxed = false;

  for (auto &u : used)
    for (int i = acs[u].s; i <= acs[u].t; i++)
      barns[i] += acs[u].p;

  return relaxed;
}

int eval(vector<ac> &acs, vector<int> &barns, int idx, vector<int> &used) {
  int res;
  if (idx == acs.size()) {
    res = 0;
    if (is_relaxed(acs, barns, used))
      for (auto u : used)
        res += acs[u].m;
    else
      res = 1e8;
    return res;
  }

  used.emplace_back(idx);
  res = eval(acs, barns, idx + 1, used);
  used.pop_back();
  res = min(res, eval(acs, barns, idx + 1, used));

  return res;
}

int eval(vector<ac> &acs, vector<int> &barns) {
  vector<int> used;
  return eval(acs, barns, 0, used);
}

int main(int argc, char const *argv[]) {
  int N, M;
  int s, t, c, m;
  vector<int> barns(101, 0);
  vector<ac> acs;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> s >> t >> c;
    for (int j = s; j <= t; j++)
      barns[j] = c;
  }

  for (int i = 0; i < M; i++) {
    cin >> s >> t >> c >> m;
    acs.emplace_back(ac{s, t, c, m});
  }

  cout << eval(acs, barns) << endl;
  return 0;
}
