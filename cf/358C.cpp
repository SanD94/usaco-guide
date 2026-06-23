// https://codeforces.com/problemset/problem/358/C
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
using namespace std;

vector<string> push_str = {
    "",
    "pushStack",
    "pushQueue",
    "pushFront",
    "pushBack"
};

vector<string> pop_str = {
    "popStack",
    "popQueue",
    "popFront"
};

priority_queue<pair<int, int>> pq;

int main() {
    int n, k;
    cin >> n;
    
    vector<int> str_indices(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> k;
        while (k && i < n) {
            pq.push({ k, i++ });
            cin >> k;
        }
        int num_idx = 0;
        while(!pq.empty()) {
            auto [x, idx] = pq.top(); pq.pop();
            str_indices[idx] = min(4, ++num_idx);
        }
    }
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (str_indices[i] == 0) {
            idx = min(3, idx);
            cout << idx;
            for(int j = 0; j < idx; j++) cout << " " << pop_str[j];
            cout << endl;
            idx = 0;
            continue;
        }
        idx = max(idx, str_indices[i]);

        cout << push_str[str_indices[i]] << endl;
    }
    return 0;
}



