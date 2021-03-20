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
  int n, m, q;
  vector<vector<int>> graph;

  void Read() {
    cin >> n >> m >> q;
    graph.resize(n + 1);
    for (int i = 1; i <= m; ++i) {
      int u, v;
      cin >> u >> v;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
  }
  
  vector<int> par;
  vector<int> seen;
  vector<int> sz;
  vector<int> diameter;

  void Solve() {
    par.resize(n + 1);
    seen.resize(n + 1);
    sz.resize(n + 1);
    diameter.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      if (!seen[i]) {
        Pre(i, i);
        diameter[i] = GetDiameter(GetDiameter(i, 0).second, 0).first;
      }
    }
    while (q--) {
      int typ;
      cin >> typ;
      if (typ == 1) {
        int x;
        cin >> x;
        cout << diameter[Par(x)] - 1 << '\n';
      } else {
        int x, y;
        cin >> x >> y;
        Merge(x, y);
      }
    }
  }

  void Pre(int u, int r) {
    seen[u] = true;
    par[u] = r;
    ++sz[r];
    for (auto &v : graph[u]) {
      if (seen[v]) continue;
      Pre(v, r);
    }
  }

  pair<int, int> GetDiameter(int u, int p) {
    pair<int, int> res = {1, u};
    for (auto &v : graph[u]) {
      if (v == p) continue;
      pair<int, int> nxt = GetDiameter(v, u);
      res = max(res, make_pair(nxt.first + 1, nxt.second));
    }
    return res;
  }

  int Par(int x) {
    return x == par[x] ? x : par[x] = Par(par[x]);
  }

  void Merge(int x, int y) {
    x = Par(x), y = Par(y);
    if (x == y) return;
    if (sz[x] < sz[y]) {
      swap(x, y);
    }
    sz[x] += sz[y];
    par[y] = x;
    diameter[x] = max({diameter[x], diameter[y], (diameter[x] / 2 + 1) + (diameter[y] / 2 + 1)});
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}