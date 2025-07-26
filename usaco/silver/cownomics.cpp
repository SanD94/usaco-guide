// https://usaco.org/index.php?page=viewproblem2&cpid=739
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

vector<string> spotty;
vector<string> plain;
int N, M;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int find_index(char ch) {
  string code = "ATGC";
  return code.find(ch);
}

bool diff(int a, int b, int c) {
  vector<int> diffs(64, 0);
  for(int i = 0; i < N; i++) {
    int index = find_index(spotty[i][a]) +
      4 * find_index(spotty[i][b]) +
      16 * find_index(spotty[i][c]);
    diffs[index]++;
  }
  for(int i = 0; i < N; i++) {
    int index = find_index(plain[i][a]) +
      4 * find_index(plain[i][b]) +
      16 * find_index(plain[i][c]);
    if (diffs[index]) return false;
  }

  return true;
}

int main(int argc, char const *argv[]) {
  set_io("cownomics");
  cin >> N >> M;
  copy_n(istream_iterator<string>(cin), N, back_inserter(spotty));
  copy_n(istream_iterator<string>(cin), N, back_inserter(plain));
  
  int res = 0;
  for(int i = 0; i < M; i++)
    for(int j = i + 1; j < M; j++)
      for(int k = j + 1; k < M; k++)
        if(diff(i, j, k)) res ++;
  cout << res << endl;

  return 0;
}
