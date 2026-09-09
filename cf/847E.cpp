// https://codeforces.com/contest/847/problem/E
#include <iostream>
#include <vector>
using namespace std;

int cover(int pacman, int lf, int rf) {
    int x = pacman - lf;
    int y = rf - pacman;

    if (x < 0) return y;
    if (y < 0) return x;
    return min(x + 2*y, 2*x + y);
}

bool can_eat(vector<int>& food, vector<int>& pacman, int T) {
    size_t food_idx = 0;
    for (int p: pacman) {
        if (food_idx == food.size()) return true;

        int lf = food[food_idx];

        while (
            food_idx < food.size() && 
            cover(p, lf, food[food_idx]) <= T
        ) food_idx++; 
    }
    return food_idx == food.size();
}


int main() {
    int n;
    char c;
    vector<int> pacman, food;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        if (c == '*') food.push_back(i);
        if (c == 'P') pacman.push_back(i);
    }
    int l = 0, r = 3 * n / 2;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (can_eat(food, pacman, m)) r = m;
        else l = m + 1;
    }

    cout << l << endl;
    return 0;
}

