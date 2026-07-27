// https://codeforces.com/contest/702/problem/C
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

using lli = long long int;

int main() {
    int n, m;
    cin >> n >> m;
    vector<lli> cities, cells;
    copy_n(istream_iterator<lli>(cin), n, back_inserter(cities));
    copy_n(istream_iterator<lli>(cin), m, back_inserter(cells));

    int i_cell = 0;
    lli res = 0;

    for (auto city : cities) {
        while (i_cell + 1 < m && abs(cells[i_cell + 1] - city) <= abs(cells[i_cell] - city))
            i_cell++;
        res = max(res, abs(cells[i_cell] - city));
    }

    cout << res << endl;

    return 0;
}






