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

void exhaust(int idx, int lhs, int rhs, vector<int> &deck) {
  int cur_res;
  if (idx == 4) {
    for (int i = 0; i < 4; i++) {
      if (i == 3 && (rhs == 0 || lhs % rhs != 0)) continue;
      cur_res = ops[i](lhs, rhs);
      if (cur_res <= 24) res = max(res, cur_res);
    }
    return;
  }
  // lhs op rhs, deck[idx]
  for (int i = 0; i < 4; i++) {
    if (i == 3 && (rhs == 0 || lhs % rhs != 0)) continue;
    cur_res = ops[i](lhs, rhs);
    exhaust(idx + 1, cur_res, deck[idx], deck);
  }
  // lhs, rhs op deck[idx]
  for (int i = 0; i < 4; i++) {
    if (i == 3 && (deck[idx] == 0 || rhs % deck[idx] != 0)) continue;
    cur_res = ops[i](rhs, deck[idx]);
    exhaust(idx + 1, lhs, cur_res, deck);
  }
}

void exhaust(vector<int> &deck) {
  exhaust(2, deck[0], deck[1], deck);
}


int eval(vector<int> &deck) {
  sort(deck.begin(), deck.end());
  res = 0;
  do {
    exhaust(deck);
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
