// https://usaco.org/index.php?page=viewproblem2&cpid=1491
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int N;
vector<int> A;
vector<int> B;
vector<int> K;
vector<vector<int>> K_rev;
vector<int> res;

void preprocess() {
    K.resize(N + 1);
    res.resize(N + 1);
    for (auto i = 0; i < N; i++) {
        K[i+1] = K[i] + (A[i] == B[i]);
    }
}

int rev_sum(int i, int j) {
    if (i > j) return 0;
    if (i == j) 
        K_rev[i][j] = A[i] == B[j];
    if (K_rev[i][j] != -1) return K_rev[i][j];
    K_rev[i][j] = (A[i] == B[j]) + rev_sum(i+1, j-1) + (A[j] == B[i]);
    return K_rev[i][j];
}


void eval() {
    K_rev.resize(N);
    for (int i = 0; i < N; i++) {
        K_rev[i].resize(N);
        fill(begin(K_rev[i]), end(K_rev[i]), -1);
    }
    
    for(int i = 0; i < N; i++)
        for(int j = 0; j+i < N; j++) {
            int cnt = K[j] + rev_sum(j, j+i) + K[N] - K[j+i+1];
            res[cnt]++;
        }
}

int main(int argc, char const *argv[]) {
    int i, j;
    
    cin >> N;
    copy_n(istream_iterator<int>(cin), N, back_inserter(A));
    copy_n(istream_iterator<int>(cin), N, back_inserter(B));

    preprocess();
    eval();

    copy(res.begin(), res.end(), ostream_iterator<int>(cout, "\n"));

    return 0;
}

