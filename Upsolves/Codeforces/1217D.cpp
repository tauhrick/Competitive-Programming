#ifndef local
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "debug.hpp"
#endif

class task {
 public:
  void perform() {
    read();
    solve();
  }
 
 private:
  int n, m;  
  vector<vector<pair<int, int>>> graph;
  vector<bool> seen;
  vector<int> col;
  set<int> parents;

  void read() {
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back({v, i});
    } 
  }
 
  void solve() {
    seen.resize(n + 1);
    col.resize(m + 1);
    for (int i = 1; i <= n; ++i) {
      if (!seen[i]) {
        dfs(i);
      }
    }
    cout << *max_element(col.begin(), col.end()) << '\n';
    for (int i = 1; i <= m; ++i) {
      cout << col[i] << " \n"[i == m];
    }
  }

  void dfs(int u) {
    seen[u] = true;
    parents.insert(u);
    for (auto &[v, e] : graph[u]) {
      if (seen[v]) {
        col[e] = (parents.count(v) ? 2 : 1);
      } else {
        col[e] = 1;
        dfs(v);
      }
    }
    parents.erase(u);
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  task t;
  t.perform();
  return 0;
}