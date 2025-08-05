// https://usaco.org/index.php?page=viewproblem2&cpid=1324
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

enum Type { N, TV, IV, C, P, S };

int find_index(const string &s) {
  string types("ntic");
  for (int i = 0; i < types.size(); i++)
    if (s[0] == types[i])
      return i;
  return -1;
}

string create_string(const vector<vector<string>> &grammar, int t1, int t2,
                     int M, int J) {
  stringstream ss("");
  Type cur_type = N;
  int in = 0;
  while (t1 >= 0 || t2 >= 0 || M >= 0 || J >= 0) {
    switch (cur_type) {
    case N:
      ss << grammar[cur_type][in++];
      if (t1 >= 0 || t2 >= 0 || M >= 0)
        cur_type = S;
      break;

    case IV:
      ss << grammar[cur_type][t1--];

    default:
      break;
    }
  }
  return ss.str();
}

// C comma
// P period
pair<int, string> eval(const vector<vector<string>> &grammar, int C, int P) {
  int W = 0;
  int t1 = 0, t2 = 0, M = 0, J = 0;
  for (int i = 0; i < grammar[IV].size(); i++)
    for (int j = 0; j < grammar[TV].size(); j++) {
      if (i + 2 * j > grammar[N].size())
        continue;
      int T = i + j;
      // number of conjuctions
      int curJ = min((int)grammar[C].size(), T / 2);
      if (T - curJ > P)
        continue;
      // M number of commas
      int curM = min((int)grammar[N].size() - i - 2 * j, C);
      if (j == 0)
        curM = 0;
      // total words
      int curW = 2 * i + 3 * j + curM + curJ;
      if (curW > W) {
        W = curW;
        t1 = i, t2 = j, M = curM, J = curJ;
      }
    }
  string res = create_string(grammar, t1, t2, M, J);
  return {W, res};
}

int main(int argc, char const *argv[]) {
  int t, N, C, P;
  string w, type;

  cin >> t;
  while (t--) {
    vector<vector<string>> grammar(4, vector<string>());
    cin >> N >> C >> P;
    for (int i = 0; i < N; i++) {
      cin >> w >> t;
      int idx = find_index(type);
      grammar[idx].emplace_back(w);
    }
    auto [res_l, res_s] = eval(grammar, C, P);
    cout << res_l << endl << res_s << endl;
  }
  return 0;
}
