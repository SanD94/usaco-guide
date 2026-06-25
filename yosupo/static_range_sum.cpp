// https://judge.yosupo.jp/problem/static_range_sum
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

using lli = long long int;

void preprocess(vector<lli> &seq, vector<lli> &sum) {
    for (size_t i = 1; i < seq.size(); i++)
        sum[i] = sum[i-1] + seq[i];
}

int main() {
    int n, q;
    int b, e;

    cin >> n >> q;
    vector<lli> seq(n+1), sum(n+1);

    copy_n(istream_iterator<lli>(cin), n, begin(seq)+1);

    preprocess(seq, sum);

    while(q--) {
        cin >> b >> e;
        cout << sum[e] - sum[b] << endl;
    }
    
}

