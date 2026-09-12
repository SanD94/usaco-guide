// https://codeforces.com/contest/1486/problem/D
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

vector<int> calc_prefix(vector<int>& arr, int m) {
    vector<int> res(arr.size() + 1);
    for (size_t i = 0; i < arr.size(); i++)
        res[i+1] = res[i] + (arr[i] < m ? -1 : 1);
    return res;
}

bool eval(vector<int>& arr, int k) {
    int mn = arr[0];
    for (size_t i = 0; i + k < arr.size(); i++) {
        mn = min(mn, arr[i]);
        if (arr[i+k] - mn > 0) return true;
    }
    return false;

}

int main() {
    int n, k;
    vector<int> arr;
    cin >> n >> k;
    copy_n(istream_iterator<int>(cin), n, back_inserter(arr));

    int l = 1, r = n;
    while (l < r) {
        int m = l + (r - l + 1) / 2;
        vector<int> p = calc_prefix(arr, m);
        if (eval(p, k)) l = m;
        else r = m - 1;
    }

    cout << l << endl;
    
    return 0;
}
