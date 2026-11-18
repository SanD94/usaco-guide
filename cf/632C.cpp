// https://codeforces.com/problemset/problem/632/C
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

#define all(x) begin(x), end(x)



int main() {
    int n;
    vector<string> elems;
    
    cin >> n;
    copy_n(istream_iterator<string>(cin), n, back_inserter(elems));

    auto comp = [](const string& lhs, const string& rhs) {
        return lhs + rhs < rhs + lhs;
    };

    sort(all(elems), comp);
    for (int i = 0; i < n; i++)
        cout << elems[i];


    return 0;
}


