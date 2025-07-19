// https://usaco.org/index.php?page=viewproblem2&cpid=831
#include <iostream>
#include <vector>
using namespace std;

struct node {
  node *prev;
  node *next;
  int val;
};

void set_node(node *n, node *prev, node *next, int val) {
  n->prev = prev;
  n->next = next;
  n->val = val;
}


void set_io(string s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}

int main(int argc, char const *argv[]) {
  set_io("censor");
  
  string S, T;
  cin >> S >> T;
  vector<node*> linked(S.length() + 2);
  
  for (int i = 0; i < S.length() + 2; i++) linked[i] = new node{};
  set_node(linked[0], NULL, linked[1], -1);
  for (int i = 1; i <= S.length(); i++)
    set_node(linked[i], linked[i-1], linked[i+1], i - 1);
  set_node(linked[S.length() + 1], linked[S.length()], NULL, -1);


  for (node *n = linked[1]; n->val != -1; n = n->next) {
    bool removed = true;
    node *k = n;
    int i = 0;
    for (; i < T.length() && k; i++, k = k->next)
      if (S[k->val] != T[i]) {
        removed = false;
        break;
      }
    if (removed && i == T.length()) {
      n->prev->next = k;
      k->prev = n->prev;
      for(int i = 0; i <= T.length() && n != linked[0]; i++) n = n->prev;
    }
  }
  
  node *n = linked[0]->next;
  while (n->val != -1) {
    cout << S[n->val];
    n = n->next;
  }


  cout << endl;

  return 0;
}
