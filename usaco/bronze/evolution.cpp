// https://usaco.org/index.php?page=viewproblem2&cpid=941
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int N;
int t;
vector<vector<string>> elem;
set<string> features;

string s;

string eval() {
    for (auto s1: features) {
        for (auto s2: features) {
            if (s1 == s2) continue;
            bool only_a = false;
            bool only_b = false;
            bool both = false;
            for (auto f_node : elem) {
                bool cur_a = false;
                bool cur_b = false;
                bool cur_both = false;
                for(auto f : f_node) {
                    if (s1 == f) cur_a = true;
                    if (s2 == f) cur_b = true;
                }
                cur_both = cur_a & cur_b;
                only_a |= cur_a & (cur_a ^ cur_b);
                only_b |= cur_b & (cur_a ^ cur_b);
                both = both | cur_both;
            }
            if (only_a && only_b && both) return "no";
        }
    }
    return "yes";
}

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    set_io("evolution");
    cin >> N;
    for (int i = 0; i < N; i++) {
        vector<string> cur {};
        cin >> t;
        while (t--) {
            cin >> s;
            cur.push_back(s);
            features.insert(s);
        }
        elem.push_back(cur);
    }
    cout << eval() << endl;
    return 0;
}
