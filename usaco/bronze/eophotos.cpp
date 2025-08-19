// https://usaco.org/index.php?page=viewproblem2&cpid=1084
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
  int N, even = 0, odd = 0, cid;

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> cid;
    (cid % 2) ? odd++ : even++;
  }

  // First attempt was to think about consuming all and handle
  // the remainders accordingly (like sim), which leaves one to handle
  // different cases at once. (turn and even-odd pairs)
  // instead try to make even and odd as close as possible
  // 2 odd makes 1 even.
  // e = o or e = o + 1 is a solution

  while (odd > even) {
    odd -= 2;
    even++;
  }
  even = min(even, odd + 1);

  cout << even + odd << endl;

  return 0;
}
