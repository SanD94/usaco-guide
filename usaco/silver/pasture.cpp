// https://usaco.org/index.php?page=viewproblem2&cpid=1063
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

using lli = long long int;
using pi = pair<int, int>;


namespace std {

template<class A, class B>
istream& operator>>(istream& is, pair<A,B>& p) {
    return is >> p.first >> p.second;
}
}

int n;
vector<pi> cows;
vector<vector<int>> pref;


void preprocess() {
    sort(begin(cows), end(cows), [](pi a, pi b) {
        return a.second < b.second;
    });
    for (int i = 0; i < n; i++) cows[i].second = i;
    sort(begin(cows), end(cows));
    for (int i = 0; i < n; i++) cows[i].first = i;

    pref.assign(n+1, vector<int>(n+1));
    for(int i = 0; i < n; i++)
        pref[cows[i].first+1][cows[i].second+1] = 1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            pref[i+1][j+1] += pref[i][j+1] + pref[i+1][j] - pref[i][j];
}

int sum_pref(int l, int b, int r, int t) {
    return pref[r][t] - pref[r][b] - pref[l][t] + pref[l][b];
}


lli eval() {
    lli res = 0;
    res += n + 1;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int left = min(cows[i].first, cows[j].first);
            int right = max(cows[i].first, cows[j].first);
            int top = max(cows[i].second, cows[j].second);
            int bottom = min(cows[i].second, cows[j].second);
            res += sum_pref(left, 0, right+1, bottom+1) * sum_pref(left, top, right+1, n); 
        }

    return res; 
}




int main() {
    cin >> n;
    copy_n(istream_iterator<pi>(cin), n, back_inserter(cows));
    preprocess();
    cout << eval() << endl;
    return 0;
}


