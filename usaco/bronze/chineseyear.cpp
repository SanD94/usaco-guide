// https://usaco.org/index.php?page=viewproblem2&cpid=1107
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

int main(int argc, char const *argv[]) {
  int N;
  const string bessie = "Bessie", elsie = "Elsie";
  map<string, int> cow_years{{bessie, 0}};
  map<string, int> years{{"Ox", 0},     {"Tiger", 1},  {"Rabbit", 2},
                         {"Dragon", 3}, {"Snake", 4},  {"Horse", 5},
                         {"Goat", 6},   {"Monkey", 7}, {"Rooster", 8},
                         {"Dog", 9},    {"Pig", 10},   {"Rat", 11}};
  cin >> N;
  for (int i = 0; i < N; i++) {
    vector<string> sentence;
    copy_n(istream_iterator<string>(cin), 8, back_inserter(sentence));
    string next_cow = sentence[0];
    int next_y_cow = years[sentence[4]];
    string prev_cow = sentence[7];
    int prev_y_cow = ((cow_years[prev_cow] % 12) + 12) % 12;
    int dir = sentence[3] == "next" ? 1 : -1;
    int leap = (dir * (next_y_cow - prev_y_cow) + 12) % 12;
    leap *= dir;
    if (leap == 0)
      leap = 12 * dir;
    cow_years[next_cow] = cow_years[prev_cow] + leap;
  }
  cout << abs(cow_years[elsie]) << endl;
  return 0;
}
