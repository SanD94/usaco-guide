// https://usaco.org/index.php?page=viewproblem2&cpid=615
#include <array>
#include <iostream>
using namespace std;


void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
    set_io("pails");
    array<bool, 1001> mark{};
    int X, Y, M, res = 0;
    cin >> X >> Y >> M;

    mark[0] = true;
    for(int i = X; i <= M; i++) if (mark[i-X]) mark[i] = true;
    for(int i = Y; i <= M; i++) if (mark[i-Y]) mark[i] = true;
    for (int i = 0; i <= M; i++) if (mark[i]) res = i;
    cout << res << endl;
    return 0;
}
