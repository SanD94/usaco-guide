// https://usaco.org/index.php?page=viewproblem2&cpid=831
#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <numeric>
using namespace std;

array<string, 3> ttt;

int cow_wins(char ch) {
  if (ch == ttt[0][0] && ch == ttt[1][1] && ch == ttt[2][2])
    return 1;
  if (ch == ttt[0][2] && ch == ttt[1][1] && ch == ttt[2][0])
    return 1;

  for (int i = 0; i < 3; i++) {
    if (ch == ttt[i][0] && ch == ttt[i][1] && ch == ttt[i][2])
      return 1;
    if (ch == ttt[0][i] && ch == ttt[1][i] && ch == ttt[2][i])
      return 1;
  }
  return 0;
}

bool check3(char ch1, char ch2, char a, char b, char c) {
  if (a != ch1 && a != ch2) return false;
  if (b != ch1 && b != ch2) return false;
  if (c != ch1 && c != ch2) return false;
  
  if (ch1 != a && ch1 != b && ch1 != c) return false;
  if (ch2 != a && ch2 != b && ch2 != c) return false;
  
  return true;
}

int team_wins(char ch1, char ch2) {
  if (check3(ch1, ch2, ttt[0][0], ttt[1][1], ttt[2][2]))
    return 1;
  if (check3(ch1, ch2, ttt[0][2], ttt[1][1], ttt[2][0]))
    return 1;

  for (int i = 0; i < 3; i++) {
    if (check3(ch1, ch2, ttt[i][0], ttt[i][1], ttt[i][2]))
      return 1;
    if (check3(ch1, ch2, ttt[0][i], ttt[1][i], ttt[2][i]))
      return 1;
  }

  return 0;
}

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("tttt");
  copy(istream_iterator<string>(cin), istream_iterator<string>(), ttt.begin());

  // single claim
  int res = 0;
  for (int i = 0; i < 26; i++)
    res += cow_wins('A' + i);
  cout << res << endl;

  // team claim
  res = 0;
  for (int i = 0; i < 26; i++)
    for (int j = i+1; j < 26; j++)
      res += team_wins('A' + i, 'A' + j);
  cout << res << endl;

  return 0;
}
