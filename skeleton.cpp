// C++ 17
// from codeforces.com
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>
using namespace std;

#define DEBUG(name) print(#name, name)
#define DEBUGN(name) print(#name, name, true)

// FOLD EXPRESSIONS
// templates read and write
template <typename... Args> void readln(Args &...args) { ((cin >> args), ...); }

template <typename... Args> void writeln(Args... args) {
  ((cout << args << " "), ...);
}

// This is useful when we use comma as `op`.
template <typename... Args> auto Func(Args... args) { return (args + ...); }

template <typename T, typename... Args>
void pushToVector(vector<T> &v, Args &&...args) {
  (v.push_back(forward<Args>(args)), ...);
}

template <typename T> void read_write(vector<T> input, vector<T> output) {
  copy(istream_iterator<T>(cin), istream_iterator<T>(), back_inserter(input));
  copy(output.begin(), output.end(), ostream_iterator<T>(cout, " "));
}

// class template argument deduction
template <typename T> struct point {
  T x;
  T y;
  point(T x, T y) : x(x), y(y) {}
};

template <typename T, typename U> struct S {
  T first;
  U second;
};

// deduction guide
template <typename T, typename U> S(const T &first, const U &second) -> S<T, U>;

// This capture in lambda expressions
// may not be needed in CP but who knows

struct someClass {
  int x = 0;
  void f() const { cout << x << endl; }

  void g() { x++; }
  void func() {
    auto lambda1 = [*this]() { f(); };
    auto lambda2 = [*this]() mutable { g(); };
    lambda1();
    lambda2();
  }
};

int main(int argc, char const *argv[]) {

  cout << Func(1, 2, 3, 4, 5) << endl;
  vector<int> v;
  pushToVector(v, 1, 4, 5, 8);

  int x;
  double y;
  readln(x, y);
  writeln(x, "some string", y);
  cout << endl;

  pair p2 = {14, 17.0};
  point pp = {1, 2};

  vector<int> input, output;
  read_write(input, output);

  vector<point<int>> points = {{0, 0}, {1, 0}, {0, 1}, {1, 1}};
  for (auto &[x, y] : points) {
    writeln(x, y);
  }

  // iterating over map
  map<int, string> m;
  for (auto [k, v] : m) {
    writeln("key :", k, "\n", "value :", v, "\n");
  }

  // initializer in if and switch
  set<int> s;
  if (auto [iter, ok] = s.insert(42); ok) {
    cout << "Done" << endl;
  } else {
    writeln(*iter, ok);
  }

  // non-constant c-data
  string str = "hello";
  char *p = str.data();
  p[0] = 'H';
  cout << str << endl;

  // free functions -- O(1)
  vector<int> v0 = {3, 2, 5, 1, 7, 6};
  size_t sz = size(v0);
  bool e0 = empty(v0);
  auto ptr = data(v0);

  // clamping
  cout << clamp(7, 0, 10);
  cout << clamp(7, 0, 5);
  cout << clamp(7, 10, 50);

  // finally gcd and lcm!!!
  cout << gcd(24, 60);
  cout << lcm(8, 10);

  vector<int> v1 = {1, 2, 3};
  auto &r = v1.emplace_back(10);
  r = 42;

  return 0;
}
