// https://usaco.org/index.php?page=viewproblem2&cpid=712
#include <iostream>
#include <vector>
using namespace std;


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

bool cross(vector<int> i, vector<int> j) {
  int cnt = 0;
  if (i[0] < j[0] && j[0] < i[1]) cnt--;
  if (j[0] < i[0] || i[1] < j[0]) cnt++;
  if (i[0] < j[1] && j[1] < i[1]) cnt--;
  if (j[1] < i[0] || i[1] < j[1]) cnt++;
  return cnt == 0;
}

int main(int argc, char const *argv[]) {
  set_io("circlecross");
  string circle;
  vector<vector<int>> cows;
  cin >> circle;

  for (int i = 0; i < 26; i ++) {
    char c = 'A' + i;
    vector<int> cow;
    for (int j = 0; j < 52; j++) if (circle[j] == c) cow.emplace_back(j);
    cows.emplace_back(cow);
  }
  int cnt = 0;
  for (int i = 0; i < 26; i++)
    for (int j = i + 1; j < 26; j++)
      if (cross(cows[i], cows[j])) cnt++;
  
  cout << cnt << endl;
  return 0;
}
