// https://codeforces.com/gym/102951/problem/A
#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[]) {
    array<int, 5000> x;
    array<int, 5000> y;
    int res = 0, N;
    
    cin >> N;
    copy_n(istream_iterator<int>(cin), N, x.begin());
    copy_n(istream_iterator<int>(cin), N, y.begin());
    
    for(int i = 0; i < N; i++)
        for(int j = i+1; j < N; j++) {
            int x2 = (x[i] - x[j]) * (x[i] - x[j]);
            int y2 = (y[i] - y[j]) * (y[i] - y[j]);
            res = max(res, x2 + y2);
        }
    
    cout << res << endl;
    return 0;
}
