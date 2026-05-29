// https://cses.fi/problemset/task/3175
#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> res;

void eval() {
    if (N == 1) {
        cout << 1 << endl;
        return;
    }
    if (N < 4) {
        cout << "NO SOLUTION" << endl;
        return;
    }
    if (N == 4) {
        cout << "2 4 1 3" << endl;
        return;
    }
    N -= 5;
    vector<vector<int>> vals = {
        vector<int> {1, 3, 5, 2, 4},
        vector<int> {1, 3, 5, 2, 4, 6},
        vector<int> {1, 3, 5, 2, 6, 4, 7},
        vector<int> {1, 3, 5, 2, 6, 8, 4, 7},
        vector<int> {1, 3, 5, 2, 4, 7, 9, 6, 8},
    };
    int go = 0;
    while (N >= 5) {
        for (int i = 0; i < vals[0].size(); i++)
            cout << go + vals[0][i] << " ";
        N -= 5;
        go += 5;
    }
    for (int i = 0; i < vals[N].size(); i++)
        cout << go + vals[N][i] << " ";
}

int main(int argc, char const *argv[]) {
    cin >> N;
    eval();

    return 0;
}

