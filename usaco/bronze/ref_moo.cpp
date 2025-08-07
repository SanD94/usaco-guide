// https://usaco.org/index.php?page=viewproblem2&cpid=1324
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <vector>
using namespace std;

#define IV "intransitive-verb"
#define TV "transitive-verb"
#define NOUN "noun"
#define CONJ "conjunction"

string create_p(map<string, vector<string>> &words, int t1, int t2, int C) {
  int ni = 0;
  vector<string> phrases;
  const auto &nouns = words[NOUN];
  const auto &tv = words[TV];
  const auto &iv = words[IV];
  const auto &conj = words[CONJ];

  for (int i = 0; i < t1; i++)
    phrases.emplace_back(nouns[ni++] + " " + iv[i]);

  for (int i = 0; i < t2; i++)
    phrases.emplace_back(nouns[ni++] + " " + tv[i] + " " + nouns[ni++]);

  // add comma
  if (t2 > 0) {
    string &last = phrases.back();
    for (int c = 0; c < C && ni < nouns.size(); c++)
      last.append(", " + nouns[ni++]);
  }

  int pi = 0;
  vector<string> sentences;
  for (auto c : conj) {
    if (pi + 1 >= phrases.size())
      break;
    auto fp = phrases[pi++];
    auto sp = phrases[pi++];
    sentences.emplace_back(fp + " " + c + " " + sp);
  }
  sentences.insert(sentences.end(), phrases.begin() + pi, phrases.end());

  string res("");
  for (auto &s : sentences)
    res.append(s + ". ");
  if (!res.empty())
    res.pop_back();

  return res;
}

pair<int, string> eval(map<string, vector<string>> &words, int C, int P) {
  int W = 0;
  int t1 = 0, t2 = 0;
  string res = "";
  for (int i = 0; i <= words[IV].size(); i++)
    for (int j = 0; j <= words[TV].size(); j++) {
      int nouns_left = words[NOUN].size() - i - 2 * j;
      if (nouns_left < 0)
        break;

      int T = i + j;
      int conj_used = min((int)words[CONJ].size(), T / 2);
      if (T - conj_used > P)
        break;

      int extra = j > 0 ? min(nouns_left, C) : 0;

      int curW = 2 * i + 3 * j + extra + conj_used;
      if (curW > W)
        t1 = i, t2 = j, W = curW;
    }

  res = create_p(words, t1, t2, C);

  return {W, res};
}

int main(int argc, char const *argv[]) {
  int t, N, C, P;
  string w, type;

  cin >> t;
  while (t--) {
    map<string, vector<string>> words{
        {NOUN, {}},
        {IV, {}},
        {TV, {}},
        {CONJ, {}},
    };

    cin >> N >> C >> P;
    for (int i = 0; i < N; i++) {
      cin >> w >> type;
      words[type].emplace_back(w);
    }

    auto [res_l, res_s] = eval(words, C, P);
    cout << res_l << endl << res_s << endl;
  }
  return 0;
}
