// https://usaco.org/index.php?page=viewproblem2&cpid=1088
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

#define all(x) begin(x), end(x)

using lli = long long int;

int main(int argc, char const *argv[]) {
  int N, point;
  cin >> N;
  lli vert_sum = 0, hort_sum = 0;
  vector<vector<int>> horizontal(N, vector<int>(2, 0));
  vector<vector<int>> vertical(N, vector<int>(2, 0));
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) {
      cin >> point;
      horizontal[i][j%2] += point;
      vertical[j][i%2] += point;
    }
  for (int i = 0; i < N; i++) {
    hort_sum += *max_element(all(horizontal[i]));
    vert_sum += *max_element(all(vertical[i]));
  }
  
  cout << max(hort_sum, vert_sum) << endl;

  return 0;
}
