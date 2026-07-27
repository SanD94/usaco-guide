// https://codeforces.com/contest/279/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


using lli = long long int;

int main() {
    lli n, t;
    vector<lli> books;
    cin >> n >> t;
    copy_n(istream_iterator<lli>(cin), n, back_inserter(books));

    int res = 0, cur_cnt = 0;
    lli sum = 0;
    auto left = books.begin(), right = books.begin();
    while (right != books.end()) {
        if (sum + *right <= t) {
            cur_cnt ++;
            sum += *right++;
        } else {
            cur_cnt--;
            sum -= *left++;
        }
        res = max(res, cur_cnt);
    }
    cout << res << endl;
    return 0;
}






