// https://codeforces.com/contest/847/problem/B
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    int n;
    vector<int> arr;
    vector<vector<int>> res;
    cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(arr));

    for (auto x : arr) {
        size_t l = 0, r = res.size();
        while (l < r) {
            size_t m = l + (r - l) / 2;
            if (res[m].back() > x) l = m + 1;
            else r = m;
        }

        if (l == res.size()) res.push_back(vector<int>());
        res[l].push_back(x);
    }


    for (auto &s : res)
        for (size_t i = 0; i < s.size(); i++)
            cout << s[i] << ((i != s.size() - 1) ? " " : "\n");
    

    return 0;
}


