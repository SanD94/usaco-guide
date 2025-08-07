// https://usaco.org/index.php?page=viewproblem2&cpid=893
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

map<string, set<int>> common;
vector<vector<string>> props;
int N, K;
string s;


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int count(int a, int b) {
  int res = 0;
  for (auto &s : props[a]) 
    if (common[s].find(b) != common[s].end()) res++;
  return res + 1;
}


int main(int argc, char const *argv[]) {
  set_io("guess");
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s >> K;
    props.emplace_back(vector<string>());
    for (int j = 0; j < K; j++) {
      cin >> s;
      props[i].emplace_back(s);
      common[s].insert(i);
    }
  }
  
  int res = 0;
  for (int i = 0; i < N; i++) 
    for (int j = i + 1; j < N; j++)
      res = max(res, count(i, j));
  
  cout << res << endl;

  return 0;
}
