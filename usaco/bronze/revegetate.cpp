// https://usaco.org/index.php?page=viewproblem2&cpid=916
#include <iostream>
#include <vector>
using namespace std;

struct graph {
  int N, M;
  vector<vector<int>> G;

  friend istream &operator>>(istream &is, graph &G) {
    is >> G.N >> G.M;
    G.G.resize(G.N + 1, vector<int>(G.N + 1, 0));
    for (int i = 1; i <= G.N; i++)
      G.G[i][i] = 1;
    int a, b;
    for (int i = 0; i < G.M; i++) {
      is >> a >> b;
      G.G[a][b] = G.G[b][a] = 1;
    }
    return is;
  }

  friend ostream &operator<<(ostream &os, graph &G) {
    for (int i = 1; i <= G.N; i++)
      os << G.G[i][i];
    return os << endl;
  }
};

void eval(graph &G) {
  for (int i = 1; i <= G.N; i++) {
    vector<bool> mark(5, 0);
    for (int j = 1; j < i; j++)
      if (G.G[i][j])
        mark[G.G[j][j]] = true;

    for (int j = 1; j < 5; j++)
      if (!mark[j]) {
        G.G[i][i] = j;
        break;
      }
  }
}

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("revegetate");
  graph G;
  cin >> G;
  eval(G);
  cout << G;
  return 0;
}
