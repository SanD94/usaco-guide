// https://usaco.org/index.php?page=viewproblem2&cpid=1013
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

bool is_ordered(vector<int> &arr) {
    for (int i = 1; i < arr.size(); i++)
        if (i != arr[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set_io("swap");

    int n, k;
    cin >> n >> k;
    vector<int> elems(n+1);
    pair<int, int> a0, a1;
    map<int, vector<int>> res;
    cin >> a0.first >> a0.second;
    cin >> a1.first >> a1.second;
    int step = 0;

    for (int i = 1; i <= n; i++) elems[i] = i;

    do {
        res[step++] = elems;
        vector<int> t0(elems.rend() - a0.second - 1, elems.rend() - a0.first);
        for(int i = a0.first; i <= a0.second; i++) elems[i] = t0[i - a0.first];
        vector<int> t1(elems.rend() - a1.second - 1, elems.rend() - a1.first);
        for(int i = a1.first; i <= a1.second; i++) elems[i] = t1[i - a1.first];
    } while(!is_ordered(elems));

    vector<int> cur = res[k % step];
    copy_n(cur.begin()+1, n, ostream_iterator<int>(cout, "\n"));


    return 0;
}




