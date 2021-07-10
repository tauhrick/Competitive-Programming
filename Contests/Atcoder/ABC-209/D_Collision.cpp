#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n, q;  
  vector<vector<int>> graph;
  int timer, l;
  vector<int> tin, tout;
  vector<vector<int>> up;
  vector<int> dep;

  void Read() {
    cin >> n >> q;
    graph.resize(n + 1);
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    } 
  }
 
  void Solve() {
    pre_lca(1);
    while (q--) {
      int c, d;
      cin >> c >> d;
      cout << (distance(c, d) % 2 == 0 ? "Town" : "Road") << '\n';
    } 
  }

  void dfs(int v, int p, int d) {
      dep[v] = d;
      tin[v] = ++timer;
      up[v][0] = p;
      for (int i = 1; i <= l; ++i) {
          up[v][i] = up[up[v][i - 1]][i - 1];
      }
      for (auto u : graph[v]) {
          if (u != p) {
              dfs(u, v, d + 1);
          }
      }
      tout[v] = ++timer;
  }

  bool is_ancestor(int anc, int u) {
      return tin[anc] <= tin[u] && tout[anc] >= tout[u];
  }

  int distance(int u, int v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
  }

  int lca(int u, int v) {
      if (is_ancestor(u, v)) {
          return u;
      } else if (is_ancestor(v, u)) {
          return v;
      }
      for (int i = l; i >= 0; --i) {
          if (!is_ancestor(up[u][i], v)) {
              u = up[u][i];
          }
      }
      return up[u][0];
  }

  void pre_lca(int root) {
      tin.resize(n + 1);
      tout.resize(n + 1);
      dep.resize(n + 1);
      timer = 0;
      l = int(ceil(log2(n + 1)));
      up.assign(n + 1, vector<int>(l + 1));
      dfs(root, 0, 0);
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}