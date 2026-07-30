// https://usaco.org/index.php?page=viewproblem2&cpid=918
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int min_eval(vector<int> &arr) {
    int n = arr.size();
    if (arr[n-2] - arr[0] == n-2 && arr[n-1] - arr[n-2] > 2) return 2;
    if (arr[n-1] - arr[1] == n-2 && arr[1] - arr[0] > 2) return 2;

    int r = 1, res = n;
    for (int l = 0; l < n; l++) {
        while (r < n && arr[r] - arr[l] < n) r++;
        res = min(res, n - (r - l));
    }
    return res;
}

int max_eval(vector<int> &arr) {
    int diff = 0, n = arr.size();
    for (int i = 1; i < n; i++)
        diff += arr[i] - arr[i-1] - 1;
    return max(diff - (arr[1] - arr[0] - 1), diff - (arr[n-1] - arr[n-2] - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    set_io("herding");

    int n;
    vector<int> cows;
    cin >> n;
    copy_n(istream_iterator<int>(cin), n, back_inserter(cows));
    sort(begin(cows), end(cows));

    cout << min_eval(cows) << endl;
    cout << max_eval(cows) << endl;

    return 0;
}



