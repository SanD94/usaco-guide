// https://usaco.org/index.php?page=viewproblem2&cpid=833
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
using namespace std;


int N;
map<string, int> ind;
vector<pair<int, int>> links;
string bessie, elsie;

string relate_str(int i, int j) {
    if (i == 1 && j == 1)
        return "SIBLINGS";
    // bessie and elsie are cousins
    if (i >= 2 && j >= 2)
        return "COUSINS";
    if (j == 0 || (j == 1 && i >= 2)) {
        string temp;
        temp = bessie;
        bessie = elsie;
        elsie = temp;

        int tmp;
        tmp = i; i = j; j = tmp;
    }
    // bessie or elsie is ancestor
    stringstream ss;
    if (i == 0) {
        ss << bessie;
        if (j == 1) ss << " is the mother of ";
        if (j == 2) ss << " is the grand-mother of ";
        if (j >= 3) {
            string great = "";
            for (int k = 3; k <= j; k++) great += "great-";
            ss << " is the " << great << "grand-mother of ";
        }
        ss << elsie;
        return ss.str();
    }
    // aunt relation
    if (i == 1 && j >= 2) {
        ss << bessie;
        if (j == 2) ss << " is the aunt of ";
        if (j >= 3) {
            string great = "";
            for (int k = 3; k <= j; k++) great += "great-";
            ss << " is the " << great << "aunt of ";
        }
        ss << elsie;
        return ss.str();
    }
    return "";
}

void read() {
    string s1, s2;
    int cnt = 2;
    cin >> N >> bessie >> elsie;
    ind[bessie] = 1; ind[elsie] = 2;
    for (int i = 0; i < N; i++) {
        cin >> s1 >> s2;
        if (!ind[s1]) ind[s1] = ++cnt;
        if (!ind[s2]) ind[s2] = ++cnt;
        // parent-child
        links.push_back({ind[s1], ind[s2]});
    }
}

vector<int> get_ancestor(int x, vector<int> &mother) {
    vector<int> anc;
    anc.push_back(x);
    while(mother[x]) {
        x = mother[x];
        anc.push_back(x);
    }
    return anc;
}

string eval() {
    int node_size = ind.size();
    vector<int> mother(node_size+1);
    for(auto [p, c] : links)
        mother[c] = p;

    auto all_b_ancestor = get_ancestor(1, mother);
    auto all_e_ancestor = get_ancestor(2, mother);
    for (auto i = 0; i < all_b_ancestor.size(); i++)
        for(auto j = 0; j < all_e_ancestor.size(); j++) {
        if (all_b_ancestor[i] == all_e_ancestor[j])
            return relate_str(i, j);
    }

    return "NOT RELATED";
}

void set_io(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    set_io("family");
    read();
    cout << eval() << endl;
    return 0;
}

