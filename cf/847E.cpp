// https://usaco.org/index.php?page=viewproblem2&cpid=597
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 1e5;

bool eval(vector<int>& food, vector<int>& pacman, int T) {
    size_t food_idx = 0;
    for (size_t p_idx = 0; p_idx < pacman.size() && food_idx < food.size(); p_idx++) {
        int p = pacman[p_idx];

        if (food[food_idx] < p - T) return false;

        int x = p - food[food_idx];
        x = x < 0 ? 0 : x;

        while (food_idx < food.size()) {
            int y = food[food_idx] - p;
            y = y < 0 ? 0 : y;
            if (min(x + 2*y, 2*x + y) > T) break;
            food_idx++;
        }
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
    int l = 0, r = 3 * MAXN / 2;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (eval(food, pacman, m)) r = m;
        else l = m + 1;
    }

    cout << l << endl;
    return 0;
}

