// https://www.spoj.com/problems/HAYBALE/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> diff(n+1);

    int b, e;
    for (int i = 0; i < k; i++) {
        cin >> b >> e;
        diff[b-1]++;
        diff[e]--;
    }

    for(int i = 1; i <= n; i++)
        diff[i] += diff[i-1];

    sort(begin(diff), end(diff)-1);
    cout << diff[n/2] << endl;
    
    return 0;
}
