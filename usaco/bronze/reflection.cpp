// https://usaco.org/index.php?page=viewproblem2&cpid=1491
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int res, N, U;
vector<string> map;

struct fpoint {
    float x, y;

    fpoint x_sim() {
        return { -x, y };
    }
    fpoint y_sim() {
        return {x, -y};
    }
};

struct ipoint {
    int x, y;
};

fpoint to_coord(ipoint p, float N) {
    return {
        .x = p.x + 1 - (N + 1) / 2,
        .y = p.y + 1 - (N + 1) / 2
    };
}

ipoint from_coord(fpoint p, float N) {
    return {
        .x = int(p.x + (N + 1) / 2) - 1,
        .y = int(p.y + (N + 1) / 2) - 1
    };
}

int coord_update(int i, int j, int N) {
    fpoint fcoord = to_coord({ i, j }, N);
    vector<fpoint> coords = {
        fcoord,
        fcoord.x_sim(),
        fcoord.x_sim().y_sim(),
        fcoord.y_sim()
    };
    int cnt = 0;
    for (auto &coord: coords) {
        ipoint imap = from_coord(coord, N);
        cnt += map[imap.x][imap.y] == '#';
    }
    return min(cnt, 4 - cnt);
}


void preprocess() {
    res = 0;
    for (int i = 0; i < N / 2; i++)
        for(int j = 0; j < N / 2; j++) 
            res += coord_update(i, j, N);
}

int eval() {
    return res;
}


void update(int i, int j, vector<string> &map) {
    res -= coord_update(i, j, N);
    map[i][j] = map[i][j] == '#' ? '.' : '#';
    res += coord_update(i, j, N);
}



int main(int argc, char const *argv[]) {
    int i, j;
    
    cin >> N >> U;
    copy_n(istream_iterator<string>(cin), N, back_inserter(map));

    preprocess();
    cout << eval() << endl;
    while (U--) {
        cin >> i >> j;
        i--; j--;
        update(i, j, map);
        cout << eval() << endl;
    }

    return 0;
}
