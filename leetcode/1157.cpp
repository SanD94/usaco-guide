// https://leetcode.com/problems/online-majority-element-in-subarray/
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

#define all(x) begin(x), end(x)

class MajorityChecker {
    vector<int> elems;
    vector<vector<int>> pos;
    const int K = 20;
    const int MAXN = 20'000;
public:
    MajorityChecker(vector<int>& arr) : elems(arr) {
        pos.assign(MAXN+1, vector<int>());
        for (int i = 0; i < elems.size(); i++)
            pos[elems[i]].push_back(i);
    }
    
    int query(int left, int right, int threshold) {
        right ++;
        for (int i = 0; i < K; i++) {
            int idx = rand() % (right - left) + left;
            auto lower = lower_bound(all(pos[elems[idx]]), left);
            auto upper = upper_bound(all(pos[elems[idx]]), right - 1);
            if (upper - lower >= threshold) return elems[idx];
        }
        
        return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
