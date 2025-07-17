// https://usaco.org/index.php?page=viewproblem2&cpid=1059
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


int main(int argc, char const *argv[]) {
    int elems[7];
    for (int i = 0; i < 7; i++)
        cin >> elems[i];
    sort(elems, elems + 7);
    int a = elems[6] - elems[5];
    int b = elems[6] - elems[4];
    int c = elems[6] - b - a;
    cout << a << " " << b << " " << c << endl;
    return 0;
}
