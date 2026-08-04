// https://leetcode.com/problems/online-majority-element-in-subarray/
#include <vector>

using namespace std;

#define all(x) begin(x), end(x)


class MajorityChecker {
    vector<int> elems;
public:
    MajorityChecker(vector<int>& arr) : elems(arr) {}
    
    int query(int left, int right, int threshold) {
        right++;
        vector<int> bucket(2e4+1, 0);
        int res = -1;
        for (int i = left; i < right; i++)
            if (threshold <= ++bucket[elems[i]]) res = elems[i];


        return res;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
