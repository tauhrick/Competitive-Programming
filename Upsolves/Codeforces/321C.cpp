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
  int n;
  vector<set<int>> graph;  
  vector<vector<int>> centroid_graph;  
  vector<int> sz;
  vector<int> dep;

  void Read() {
    cin >> n;
    graph.resize(n + 1);
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      graph[u].insert(v);
      graph[v].insert(u);
    }    
  }
 
  void Solve() {
    centroid_graph.resize(n + 1);
    sz.resize(n + 1);
    Pre(1, 0);
    int root = GetCentroid(1, 0, 1);
    dep.resize(n + 1);
    Dfs(root, 0);
    for (int i = 1; i <= n; ++i) {
      cout << char('A' + dep[i] - dep[root]) << " \n"[i == n];
    }
  }

  void Pre(int u, int p) {
    sz[u] = 1;
    for (auto &v : graph[u]) {
      if (v == p) continue;
      Pre(v, u);
      sz[u] += sz[v];
    }
  }

  int GetCentroid(int u, int p, int r) {
    for (auto &v : graph[u]) {
      if (v == p) continue;
      if (2 * sz[v] > sz[r]) {
        return GetCentroid(v, u, r);
      }
    }
    for (auto &v : graph[u]) {
      graph[v].erase(u);
      Pre(v, 0);
      int c = GetCentroid(v, 0, v);
      centroid_graph[u].push_back(c);
    }
    graph[u].clear();
    return u;
  }

  void Dfs(int u, int d) {
    dep[u] = d;
    for (auto &v : centroid_graph[u]) {
      Dfs(v, d + 1);
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}