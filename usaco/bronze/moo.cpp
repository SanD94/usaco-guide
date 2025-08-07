// https://usaco.org/index.php?page=viewproblem2&cpid=1324
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

enum Type { NOUN, TV, IV, CONJ };

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
  int ni = 0, si = 0;
  vector<Type> sentences(t1, IV);
  sentences.insert(sentences.end(), t2, TV);
  vector<int> indices(4, 0);

  for (auto s : sentences) {
    ss << grammar[NOUN][ni++] << " " << grammar[s][indices[s]++];
    if (s == TV)
      ss << " " << grammar[NOUN][ni++];
    if (si % 2 == 0 && J > 0)
      ss << " " << grammar[CONJ][--J] << " ";
    else
      ss << ". ";
    si++;
  }

  string res = "";
  if (!sentences.empty()) {
    ss.seekp(-2, ios_base::end); // remove last ". "

    if (sentences.back() == TV && M > 0)
      while (M--)
        ss << ", " << grammar[NOUN][ni++];

    ss << ".t";

    res = ss.str();
    res.pop_back();
  }

  return res;
}

// C comma
// P period
pair<int, string> eval(const vector<vector<string>> &grammar, int C, int P) {
  int W = 0;
  int t1 = 0, t2 = 0, M = 0, J = 0;

  for (int i = 0; i <= grammar[IV].size(); i++)
    for (int j = 0; j <= grammar[TV].size(); j++) {
      if (i + 2 * j > grammar[NOUN].size())
        break;
      int T = i + j;
      // number of conjuctions
      int curJ = min((int)grammar[CONJ].size(), T / 2);
      if (T - curJ > P)
        break;
      // M number of commas
      int curM = min((int)grammar[NOUN].size() - i - 2 * j, C);
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
      cin >> w >> type;
      int idx = find_index(type);
      grammar[idx].emplace_back(w);
    }
    auto [res_l, res_s] = eval(grammar, C, P);
    cout << res_l << endl << res_s << endl;
  }
  return 0;
}
