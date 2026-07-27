// https://cses.fi/problemset/task/1660
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


using lli = long long int;

int main() {
    lli n, t;
    vector<lli> arr;
    cin >> n >> t;
    copy_n(istream_iterator<lli>(cin), n, back_inserter(arr));

    lli res = 0;
    lli sum = 0;
    auto left = arr.begin(), right = arr.begin();
    while (right != arr.end()) {
        if (sum + *right <= t) sum += *right++;
        else sum -= *left++;
        if (sum == t) res++;
    }
    cout << res << endl;
    return 0;
}







