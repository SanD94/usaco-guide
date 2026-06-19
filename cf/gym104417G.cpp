// https://codeforces.com/gym/104417/problem/G
#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>
using namespace std;

using lli = long long int;


lli eval() {
    map<int, vector<int>> elems;
    int N;
    vector<int> seq;

    cin >> N;
    copy_n(istream_iterator<int>(cin), N, back_inserter(seq));
    for (int i = 0; i < N; i++) 
        elems[i - seq[i]].push_back(seq[i]);

    lli res = 0;
    for (auto& [index, vec] : elems) 
        for (auto it = vec.rbegin(); it != vec.rend(); it += 2) {
            if (it + 1 == vec.rend()) break;

            lli aii = *it, ai = *(it + 1);

            if (aii + ai > 0) res += aii + ai;
            else break;
        }

    return res;
}



int main() {
    int t;
    cin >> t;
    while (t--) cout << eval() << endl;
    return 0;
}

