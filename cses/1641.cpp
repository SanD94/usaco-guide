// https://cses.fi/problemset/task/1641
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


using lli = long long int;

struct elem {
    lli val;
    int pos;

    friend bool operator<(const elem &lhs, const elem &rhs) {
        return tie(lhs.val, lhs.pos) < tie(rhs.val, rhs.pos);
    }
};

int main() {
    lli n, t;
    cin >> n >> t;
    vector<elem> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i].val;
        arr[i].pos = i + 1;
    }
    sort(begin(arr), end(arr));

    auto mid = arr.begin();
    while (mid != arr.end()) {
        auto right = arr.end() - 1, left = arr.begin();
        lli cur_t = t - mid->val;

        while (left != mid && right != mid) {
            if (left->val + mid->val + right->val == t) {
                cout << left->pos << " " << mid->pos << " " << right->pos << endl;
                return 0;
            }
            if (right->val + left->val < cur_t) left++;
            else right--;
        }
        
        mid ++;
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}








