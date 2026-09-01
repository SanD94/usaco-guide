// https://codeforces.com/contest/1520/problem/F1
#include <iostream>
#include <vector>
using namespace std;

vector<int> eval(vector<int>& nums) {
    vector<int> res(nums.size() + 1, 0);
    for (size_t i = 0; i < nums.size(); i++)
        res[i + 1] = res[i] + nums[i];
    return res;
}

int main() {
    int n = 10, k = 5;
    vector<int> nums{1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
    vector<int> prefix = eval(nums);
    int res;

    cout << n << " " << 1 << " " << k << endl;
    while (true) {
        char ch;
        int a, b;
        cin >> ch;
        if (ch == '!') {
            cin >> res;
            if (res != 10) {
                cerr << "Wrong answer!" << endl;
                return 1;
            }
            return 0;
        } else {
            cin >> a >> b;
            cout << prefix[b] - prefix[a-1] << endl;
        }
    }

    return 0;
}
