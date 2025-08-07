// https://usaco.org/index.php?page=viewproblem2&cpid=639
#include <array>
#include <iostream>
using namespace std;

constexpr int MAXN {10001};

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
    set_io("diamond");
    array<int, MAXN> count{}, cum{};
    int res = 0;
    int N, K, num;
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> num;
        count[num]++;
    }
    for (int i = 1; i < MAXN; i++)
        cum[i] = cum[i-1] + count[i];
    for (int i = K + 1; i < MAXN; i++)
        res = max(res, cum[i] - cum[i - K - 1]);
    cout << res << endl;

    return 0;
}
