// https://codeforces.com/problemset/problem/701/C
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
using namespace std;

using lli = long long int;

int main() {
    int n;
    string s;
    cin >> n >> s;
    map<char, int> pokemons, caught;
    for (auto c : s) pokemons[c]++;

    auto l = s.begin(), r = s.begin();
    int res = n;
    while (r != s.end() || caught.size() == pokemons.size()) {
        if (caught.size() < pokemons.size())
            caught[*r++]++;
        if (caught.size() == pokemons.size()) {
            res = min(res, int(r - l));
            caught[*l]--;
            if (caught[*l] == 0) caught.erase(*l);
            l++;
        }
    }

    cout << res << endl;
    return 0;
}
