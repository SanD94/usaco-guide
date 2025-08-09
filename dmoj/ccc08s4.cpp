// https://dmoj.ca/problem/ccc08s4
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

vector<function<int(int, int)>> ops = {plus<int>(), minus<int>(),
                                       multiplies<int>(), divides<int>()};

int res;

void par_check(int idx, vector<int> s, vector<int> sops, vector<int> &deck, vector<int> &iops) {
  if (idx == 3) {
    while (sops.size()) {
      int a, b, c, op;
      b = s.back(), s.pop_back();
      a = s.back(), s.pop_back();
      op = sops.back(), sops.pop_back();
      if (op == 3 && (b == 0 || a % b != 0)) return;
      c = ops[op](a, b);
      s.push_back(c);
    }
    int cur_res = s[0];
    if (cur_res <= 24) res = max(res, cur_res);
    return;
  }
  // not do the calc add an operation
  s.push_back(deck[idx + 1]);
  sops.push_back(iops[idx]);
  par_check(idx + 1, s, sops, deck, iops);
  sops.pop_back();
  s.pop_back();
  
  // do the calc and add the rest
  int a, b, c, op;
  b = s.back(), s.pop_back();
  a = s.back(), s.pop_back();
  op = sops.back(), sops.pop_back();
  if (!(op == 3 && (b == 0 || a % b != 0))) {
    c = ops[op](a,b);
    s.push_back(c);
    s.push_back(deck[idx + 1]);
    sops.push_back(iops[idx]);
    par_check(idx + 1, s, sops, deck, iops);
  } 

}

void par_check(vector<int> &deck, vector<int> &iops) {
  vector<int> s, sops;
  s.push_back(deck[0]);
  s.push_back(deck[1]);
  sops.push_back(iops[0]);
  par_check(1, s, sops, deck, iops);
}

int eval(vector<int> &deck) {
  sort(deck.begin(), deck.end());
  res = 0;
  do {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++) {
          vector<int> iops {i, j, k};
          par_check(deck, iops);
        }
  } while (next_permutation(deck.begin(), deck.end()));
  return res;
}

int main(int argc, char const *argv[]) {
  int t;
  cin >> t;
  while (t--) {
    vector<int> deck;
    copy_n(istream_iterator<int>(cin), 4, back_inserter(deck));
    cout << eval(deck) << endl;
  }

  return 0;
}
