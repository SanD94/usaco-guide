// https://usaco.org/index.php?page=viewproblem2&cpid=1060
#include <array>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

constexpr int MAXN {101};

int main(int argc, char const *argv[]) {
    array<int, MAXN> nums{}, cum{};
    int res = 0;
    int N, num;

    cin >> N;
    copy_n(istream_iterator<int>(cin), N, nums.begin());
    
    for (int i = 0; i < N; i++)
        cum[i+1] = cum[i] + nums[i];
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            int sum = cum[j] - cum[j-i];
            for (int k = j-i; k < j; k++)
                if (nums[k] * i == sum) {
                    res ++;
                    break;
                }
        }
    }
    cout << res << endl;
    return 0;
}
