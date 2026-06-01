// https://usaco.org/index.php?page=viewproblem2&cpid=691
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int rhs, lhs;
string chart;
vector<vector<int>> chart_map;

int get_state(int i, int j) {
    if (j < i) return chart_map[i][j];
    int x = chart_map[j][i];
    if (x == 0) return 3;
    if (x == 3) return 0;
    return x;
}

vector<int> get_hand(int index) {
    vector<int> res;
    for (int i = 0; i < N; i++) {
        int state = get_state(index, i);
        res.push_back(state);
    }
    return res;
}


int eval(int rhs, int lhs) {
    vector<int> chartr = get_hand(rhs);
    vector<int> chartl = get_hand(lhs);
    vector<int> elem;

    for (int i = 0; i < N; i++)
        elem.push_back(chartr[i] | chartl[i]);


    int win_hand = 0;
    for(auto e : elem)
        if (e == 0) win_hand ++;

    return win_hand * elem.size() * 2 - win_hand * win_hand;
}

int main(int argc, char const *argv[]) {
    string wall = "LDxW";

    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> chart;
        vector<int> rchart = {};
        for (int j = 0; j < chart.size(); j++) {
            for (int k = 0; k < wall.size(); k++)
                if (wall[k] == chart[j])
                    rchart.push_back(k);
        }
        chart_map.push_back(rchart);
    }

    for (int i = 0; i < M; i++) {
        cin >> rhs >> lhs;
        rhs --; lhs --;
        cout << eval(rhs, lhs) << endl;
    }

    return 0;
}

