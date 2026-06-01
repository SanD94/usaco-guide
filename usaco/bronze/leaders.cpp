// https://usaco.org/index.php?page=viewproblem2&cpid=1275
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int N;
string s;
vector<int> leader;
vector<int> gcows, hcows;
int res;

void find_leaders(vector<int> &first, vector<int> &second) {
    int sfirst = second[0];
    int slast = second[second.size() - 1];
    if (leader[sfirst] >= slast) {
        for (auto f : first) if (f < sfirst && leader[f] >= sfirst) res++;
        
        int ffirst = first[0];
        int flast = first[first.size() - 1];
        if (leader[ffirst] >= flast && leader[ffirst] < sfirst) res++;
    }
}



int eval() {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'G') gcows.push_back(i);
        if (s[i] == 'H') hcows.push_back(i);
    }

    if (gcows[0] < hcows[0]) find_leaders(gcows, hcows);
    else find_leaders(hcows, gcows);

    return res;

}

int main(int argc, char const *argv[]) {
    cin >> N >> s;
    int n;
    for (int i = 0; i < N; i++) {
        cin >> n; n--;
        leader.push_back(n);
    }
    cout << eval() << endl;
    return 0;
}


