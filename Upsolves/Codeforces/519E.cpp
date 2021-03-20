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
  int n, m;
  vector<vector<int>> graph;
  vector<pair<int, int>> queries;

  void Read() {
    cin >> n;
    graph.resize(n + 1);
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    cin >> m;
    queries.resize(m);
    for (auto &[x, y] : queries) {
      cin >> x >> y;
    }
  }
 
  void Solve() {
    Precompute(); 
    for (auto &[x, y] : queries) {
      int lca_xy = GetLca(x, y);
      int path_len = dep[x] + dep[y] - 2 * dep[lca_xy];
      if (path_len == 0) {
        cout << n << '\n';
        continue;
      } else if (path_len % 2 != 0) {
        cout << 0 << '\n';
        continue;
      }
      if (dep[x] > dep[y]) {
        swap(x, y);
      }
      int mid_node = KthAncestor(y, path_len / 2);
      int y_comp = KthAncestor(y, path_len / 2 - 1);
      if (GetLca(mid_node, x) != mid_node) {
        cout << n - ((n - sz[mid_node]) + sz[y_comp]);
      } else {
        int x_comp = KthAncestor(x, path_len / 2 - 1);
        cout << n - (sz[x_comp] + sz[y_comp]);
      }
      cout << '\n';
    }
  }

  int lg;
  vector<vector<int>> up;
  vector<int> dep;
  vector<int> sz;

  void Precompute() {
    lg = int(log2(n)) + 1;
    up = vector(lg + 1, vector(n + 1, 0));
    dep.resize(n + 1);
    sz.resize(n + 1);
    Dfs(1, 0, 0);
  }

  void Dfs(int u, int p, int d) {
    up[0][u] = p;
    dep[u] = d;
    sz[u] = 1;
    for (int i = 1; i <= lg; ++i) {
      up[i][u] = up[i - 1][up[i - 1][u]];
    }
    for (auto &v : graph[u]) {
      if (v == p) continue;
      Dfs(v, u, d + 1);
      sz[u] += sz[v];
    }
  }

  int KthAncestor(int x, int h) {
    for (int i = 0; i <= lg; ++i) {
      if ((h >> i) & 1) {
        x = up[i][x];
      }
    }
    return x;
  }

  int GetLca(int u, int v) {
    if (dep[u] < dep[v]) {
      swap(u, v);
    }
    int diff = dep[u] - dep[v];
    u = KthAncestor(u, diff);
    if (u == v) return u;
    for (int i = lg; i >= 0; --i) {
      if (up[i][u] != up[i][v]) {
        u = up[i][u];
        v = up[i][v];
      }
    }
    return up[0][u];
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}