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

    int idx_city = 0, idx_cell = 0;
    lli res = 0;
    while (idx_city < n) {
        if (cities[idx_city] < cells[idx_cell]) {
            if (idx_cell == 0) res = max(res, cells[0] - cities[idx_city]);
            else {
                res = max(
                    res, 
                    min(
                        cells[idx_cell] - cities[idx_city],
                        cities[idx_city] - cells[idx_cell-1]
                    )
                );
            }
            idx_city ++;
        } else if (idx_cell < m - 1) {
            idx_cell++;
        } else {
            res = max(res, cities[n-1] - cells[m-1]);
            idx_city = n;
        }
    }
    cout << res << endl;

    return 0;
}






