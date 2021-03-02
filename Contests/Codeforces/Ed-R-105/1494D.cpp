#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kN = int(1e5);

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n;
  vector<vector<int>> a;
  vector<int> par;
  vector<int> salary;
  int ctr;

  void Read() {
    cin >> n;
    a = vector(n + 1, vector(n + 1, 0));
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        cin >> a[i][j];
      }
    }
  }
 
  void Solve() {
    par.resize(kN);
    salary.resize(kN);
    vector<int> nodes(n);
    iota(nodes.begin(), nodes.end(), 1);
    ctr = n;
    int head = Dfs(nodes);
    cout << ctr << '\n';
    for (int i = 1; i <= ctr; ++i) {
      cout << salary[i] << " \n"[i == ctr];
    }
    cout << head << '\n';
    for (int i = 1; i <= ctr; ++i) {
      if (i == head) continue;
      cout << i << ' ' << par[i] << '\n';
    }
  }

  int Dfs(vector<int> &child) {
    if (int(child.size()) == 1) {
      salary[child[0]] = a[child[0]][child[0]];
      return child[0];
    }
    int node = ++ctr;
    int node_salary = INT_MIN;
    for (auto &u : child) {
      for (auto &v : child) {
        node_salary = max(node_salary, a[u][v]);
      }
    }
    salary[node] = node_salary;
    set rem_child(child.begin(), child.end());
    while (!rem_child.empty()) {
      vector<int> sub_tree;
      for (auto &v : rem_child) {
        if (a[*rem_child.begin()][v] != node_salary) {
          sub_tree.push_back(v);
        }
      }
      for (auto &v : sub_tree) {
        rem_child.erase(v);
      }
      par[Dfs(sub_tree)] = node;
    }
    return node;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}