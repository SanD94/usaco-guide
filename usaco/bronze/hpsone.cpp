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
    return 3 - chart_map[j][i];
}


int eval(int rhs, int lhs) {

    int win_hand = 0;
    for (int i = 0; i < N; i++) {
        int stater = get_state(rhs, i);
        int statel = get_state(lhs, i);
        if ((stater | statel) == 0) win_hand++;
    }

    return win_hand * N * 2 - win_hand * win_hand;
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

