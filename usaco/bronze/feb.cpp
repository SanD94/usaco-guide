// https://usaco.org/index.php?page=viewproblem2&cpid=1323
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>
#include "utils/query.hpp"
using namespace std;

int N;
string S;


void eval() {
    vector<int> indices(N);
    iota(indices.begin(), indices.end(), 0);

    // check full F
    // if full add something in the beginning
    if (query::from(S) | query::all_of([](char c) { return c == 'F'; })) {
        S[0] = 'E';
    }

    auto pos = query::from(indices)
        | query::filter([](int i) { return S[i] != 'F'; })
        | query::execute();


    // count beginning and end stuff
    int edge = pos.front() + (N - 1 - pos.back());

    // (a,b) -> parity and equality check
    int mn = 0, mx = 0;
    for (int i = 0; i + 1 < (int)pos.size(); ++i) {
        int a = pos[i], b = pos[i + 1];
        bool different = S[a] != S[b];
        mn += ((b - a) & 1) ^ different;
        mx += (b - a) - different;
    }

    mx += edge;

    // if begining then inc = 1 else 2
    int inc = edge > 0 ? 1 : 2;

    // go with mn-max by inc
    vector<int> levels;
    for (int level = mn; level <= mx; level += inc) levels.push_back(level);

    cout << levels.size() << '\n';
    query::from(levels) | query::copy(ostream_iterator<int>(cout, "\n"));
}

int main() {
    cin >> N;
    cin >> S;
    eval();


    return 0;
}
