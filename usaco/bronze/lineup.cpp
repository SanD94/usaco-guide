// https://usaco.org/index.php?page=viewproblem2&cpid=965
#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>
using namespace std;

vector<string> cows = {"Bessie", "Buttercup", "Belinda", "Beatrice",
                       "Bella",  "Blue",      "Betsy",   "Sue"};

int find_cow(const string &s) {
  for (int i = 0; i < cows.size(); i++)
    if (cows[i] == s)
      return i;
  return -1;
}

bool check_condition(const vector<int> &lineup,
                     const vector<vector<bool>> &bound, int cnt) {
  for (int i = 0; i < lineup.size() - 1; i++) {
    int a = lineup[i];
    int b = lineup[i + 1];
    if (bound[a][b])
      cnt--;
  }
  if (cnt == 0)
    return true;
  return false;
}

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("lineup");

  vector<int> lineup(8);
  vector<vector<bool>> bound(8, vector<bool>(8, false));

  sort(cows.begin(), cows.end());
  iota(lineup.begin(), lineup.end(), 0);

  int N;
  cin >> N;
  string c1, c2, s;

  int full_check = 0;
  for (int i = 0; i < N; i++) {
    cin >> c1;
    for (int j = 0; j < 4; j++)
      cin >> s;
    cin >> c2;

    int cx1 = find_cow(c1), cx2 = find_cow(c2);
    bound[cx1][cx2] = true;
    bound[cx2][cx1] = true;
    full_check++;
  }

  do {
    if (check_condition(lineup, bound, full_check)) {
      for (int i = 0; i < 8; i++)
        cout << cows[lineup[i]] << endl;
      return 0;
    }
  } while (next_permutation(lineup.begin(), lineup.end()));

  return 0;
}
