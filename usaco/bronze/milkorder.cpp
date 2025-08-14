// https://usaco.org/index.php?page=viewproblem2&cpid=832
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

bool correct_order(vector<int> &placement, const vector<int> &order,
                   vector<int> &mark) {
  bool res = true;
  for (int i = 0, pi = 1; i < order.size() && pi < placement.size();
       i++, pi++) {
    if (mark[order[i]]) { // already fixed
      while (pi < placement.size() && placement[pi] != order[i])
        pi++;

      if (pi == placement.size() &&
          placement[pi - 1] != order[i]) { // fixed one not found
        res = false;
        break;
      }
      continue;
    }

    while (pi < placement.size() && placement[pi])
      pi++;

    if (pi == placement.size()) { // no place available
      res = false;
      break;
    }

    placement[pi] = order[i];
    mark[order[i]] = 2;
  }

  for (int j = 1; j < placement.size(); j++)
    if (mark[placement[j]] == 2) {
      mark[placement[j]] = 0;
      placement[j] = 0;
    }

  return res;
}

int main(int argc, char const *argv[]) {
  set_io("milkorder");
  int N, M, K, c, p, res = -1;
  bool found = false;
  cin >> N >> M >> K;

  vector<int> placements(N + 1, 0), order;
  vector<int> mark(N + 1, 0);

  copy_n(istream_iterator<int>(cin), M, back_inserter(order));
  for (int i = 0; i < K; i++) {
    cin >> c >> p;
    placements[p] = c;
    mark[c] = 1; // mark cow
    if (c == 1) {
      found = true;
      res = p;
    }
  }

  for (int i = 1; i <= N && !found; i++) {
    if (placements[i])
      continue;
    placements[i] = 1;
    mark[1] = 1;
    if (correct_order(placements, order, mark)) {
      found = true;
      res = i;
    }
    placements[i] = 0;
    mark[1] = 0;
  }
  cout << res << endl;
  return 0;
}
