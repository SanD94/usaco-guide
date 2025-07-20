// https://usaco.org/index.php?page=viewproblem2&cpid=855
#include <array>
#include <iostream>
#include <iterator>
using namespace std;

void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("mixmilk");
  array<int, 3> capacity;
  array<int, 3> milk;
  for (int i = 0; i < 3; i++)
    cin >> capacity[i] >> milk[i];

  for (int i = 0; i < 100; i++) {
    int cur = i % 3;
    int next = (i + 1) % 3;
    int transfer = min(milk[cur], capacity[next] - milk[next]);
    milk[cur] -= transfer;
    milk[next] += transfer;
  }
  copy(milk.begin(), milk.end(), ostream_iterator<int>(cout, "\n"));
  return 0;
}
