// https://usaco.org/index.php?page=viewproblem2&cpid=1445
#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

typedef long long int lli;

int N, F;
string moo;
set<string> res;
map<string, int> cnt;

bool is_moo(string s) {
    return s[0] != s[1] && s[1] == s[2];
}

void preprocess() {
    string cur = "aaa";
    for(int i = 2; i < N; i++) {
        cur[0] = moo[i - 2];
        cur[1] = moo[i - 1];
        cur[2] = moo[i];
        cnt[cur] ++;
    }
    for (auto [k, v] : cnt) {
        if (!is_moo(k)) continue;
        if (v >= F) res.insert(k);
    }
    
}

vector<string> get_candidates(int index, char c) {
    vector<string> elems;
    char tmp = moo[index];
    string s = "aaa";
    moo[index] = c;
    for (int i = -2; i <= 0; i++) {
        if (index + i < 0) continue;
        if (index + i + 2 >= N) continue;
        for(int j = 0; j < 3; j++)
            s[j] = moo[index + i + j];
        elems.push_back(s);
    }
    moo[index] = tmp;
    return elems;
}

vector<string> get_eliminations(int index) {
    vector<string> elems;
    string s = "aaa";
    for (int i = -2; i <= 0; i++) {
        if (index + i < 0) continue;
        if (index + i + 2 >= N) continue;
        for(int j = 0; j < 3; j++)
            s[j] = moo[index + i + j];
        elems.push_back(s);
    }
    return elems;
}


void eval() {
    for (int i = 0; i < 26; i++) {
        char c = i + 'a';
        for (int j = 0; j < N; j++) {
            if (moo[j] == c) continue;
            auto candidates = get_candidates(j, c);
            auto eliminations = get_eliminations(j);
            for (auto s : eliminations)
                cnt[s]--;
            for (auto cand: candidates) {
                if (!is_moo(cand)) continue;
                if (cnt[cand] + 1 >= F)
                    res.insert(cand);
            }
            for (auto s : eliminations)
                cnt[s]++;
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> N >> F;
    cin >> moo;
    preprocess();
    eval();
    cout << res.size() << endl;
    for (auto s : res)
        cout << s << endl;
    return 0;
}

