// https://usaco.org/index.php?page=viewproblem2&cpid=640
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int N, K;
vector<string> piece;
vector<vector<string>> broken;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

bool boundary(int i) {
  return (0 <= i) && (i < N); 
}

bool fit(int bi, int bj, int bxi, int byi, int bxj, int byj) {
  vector<vector<int>> count(N, vector<int>(N, 0));
  // for bi
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (broken[bi][i][j] == '#') {
        if (boundary(i + bxi) && boundary(j + byi))
          count[i + bxi][j + byi]++;
        else
          return false;
      }

  // for bj
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      if (broken[bj][i][j] == '#') {
        if (boundary(i + bxj) && boundary(j + byj))
          count[i + bxj][j + byj]++;
        else
          return false;
      }
    }

  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      if (piece[i][j] == '#' && count[i][j] != 1)
        return false;

  return true;
}

bool match(int ai, int bi) {
  for (int i = 1 - N; i <= N - 1; i++)
    for(int j = 1 - N; j <= N - 1; j++)
      for (int k = 1 - N; k <= N - 1; k++)
        for(int l = 1 - N; l <= N - 1; l++)
          if (fit(ai, bi, i, j, k, l)) return true;
  return false;
}


int main(int argc, char const *argv[]) {
  set_io("bcs");

  cin >> N >> K;
  copy_n(istream_iterator<string>(cin), N, back_inserter(piece));
  for(int i = 0; i < K; i++) {
    broken.emplace_back(vector<string>());
    copy_n(istream_iterator<string>(cin), N, back_inserter(broken[i]));
  }

  for (int i = 0; i < K; i++) 
    for (int j = i + 1; j < K; j++) 
      if (match(i, j)) {
        cout << i + 1 <<  " " << j + 1 <<  endl;
        return 0;
      }
  
  return 0;
}
