// https://codeforces.com/contest/816/problem/B
#include <iostream>
#include <vector>
using namespace std;

const int MAXT = 200'002;


int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> prefix(MAXT), diff(MAXT);

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        diff[a]++;
        diff[b+1]--;
    }

    int cur = 0;
    for (int i = 1; i < MAXT; i++) {
        cur += diff[i];
        prefix[i+1] = prefix[i] + (cur >= k);
    }


    while (q--) {
        cin >> a >> b;
        cout << prefix[b+1] - prefix[a] << endl;
    }

    return 0;
}





