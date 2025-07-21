// https://usaco.org/index.php?page=viewproblem2&cpid=1060
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

constexpr int MAXN{1001};

int main(int argc, char const *argv[]) {
  int res = 1001;
  int N, num;
  char c;

  cin >> N;
  vector<pair<int, int>> cows(N);
  for (int i = 0; i < N; i++) {
    cin >> c >> num;
    cows[i].first = num;
    cows[i].second = c == 'G' ? 1 : -1;
  }
  sort(cows.begin(), cows.end());
  vector<int> lte(N + 2), gte(N + 2);
  for (int i = 0; i < N; i++)
    lte[i + 1] = lte[i] + cows[i].second == -1;
  for (int i = N; i>= 1; i--)
    gte[i - 1] = gte[i] + cows[i-1].second == 1;
  

  cout << res << endl;
  return 0;
}
