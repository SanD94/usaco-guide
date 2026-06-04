// https://usaco.org/index.php?page=viewproblem2&cpid=1323
#include<iostream>
#include<tuple>
using namespace std;

int N;
string S;
tuple<int,int,int> res;


void eval() {
    int cur = 0;
    int cnt = 0;
    // begin
    get<2>(res) = 2;
    while (S[cur] == 'F' && cur < N) {
        cnt++;
        cur++;
    }
    if (cnt > 0) get<1>(res) += cnt;
    if (cnt > 0 && cur == N) {
        get<2>(res) = 1;
        return;
    }
    int begin = cur;
    // end
    cur = N-1;
    cnt = 0;
    while (S[cur] == 'F' && cur >= 0) {
        cnt++;
        cur--;
    }
    if (cnt > 0) get<1>(res) += cnt;
    if (cnt > 0) {
        get<2>(res) = 1;
    }
    int end = cur;
    // mid
    char ch = S[begin];
    for (int i = begin+1; i <= end; i++) {
        if (ch == S[i]) {
            get<0>(res)++;
            get<1>(res)++;
            get<2>(res) = 1;
            ch = S[i];
            continue;
        }
        int cnt = 0;
        while (S[i] == 'F') {
            cnt++;
            i++;
        }
        if (cnt % 2 == 0) {
            if (S[i] == ch) {
                get<0>(res) += 1;
                get<1>(res) += cnt + 1;
            } else {
                get<1>(res) += cnt;
            }
        } else {
            if (S[i] == ch) {
                get<1>(res) += cnt + 1;
            } else {
                get<0>(res) += 1;
                get<1>(res) += cnt;
            }
        }
        get<2>(res) = min(get<2>(res), 2);
        ch = S[i];
    }
}

int main(int argc, char const *argv[]) {
    cin >> N;
    cin >> S;
    eval();
    auto [bgn, last, inc] = res;
    cout << (last-bgn)/inc+1 << endl;

    for (int i = bgn; i <= last; i += inc)
        cout << i << endl;

    return 0;
}

