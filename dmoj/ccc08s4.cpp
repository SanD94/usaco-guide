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
void par_check(vector<int> s, vector<int> iops) {
  if (s.size() == 1) {
    int cur_res = s.back();
    if (cur_res <= 24)
      res = max(res, cur_res);
    return;
  }
  while (s.size() > 1) {
    // eval top two
    int a, b, c, op;
    b = s.back(), s.pop_back();
    a = s.back(), s.pop_back();
    op = iops.back(), iops.pop_back();
    if (op == 3 && (b == 0 || a % b != 0))
      return;
    c = ops[op](a, b);
    s.push_back(c);
    par_check(s, iops);
    s.pop_back();
  }
}

int eval(vector<int> &deck) {
  sort(deck.begin(), deck.end());
  do {
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        for (int k = 0; k < 4; k++)
          par_check(deck, vector<int>{i, j, k});
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
