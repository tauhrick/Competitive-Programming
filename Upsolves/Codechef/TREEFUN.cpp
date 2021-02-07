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
  vector<vector<int>> queries;
  vector<int> depth;
  int lg;
  vector<vector<int>> par;
  int timer = 0;
  vector<pair<int, int>> ranges;
  vector<vector<pair<int, int>>> children_ranges;

  void Read() {
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    queries.resize(m);
    for (auto &query : queries) {
      int k;
      cin >> k;
      query.resize(k);
      for (auto &node : query) {
        cin >> node;
      }
    }
  }
 
  void Solve() {
    Precompute();
    for (auto &query : queries) {
      if (int(query.size()) == 2) {
        cout << GetDistance(query[0], query[1]) - 1;
      } else {
        int u = query[0], v = query[1], w = query[2];
        vector<int> lca_pairs = {GetLca(u, v), GetLca(v, w), GetLca(w, u)};
        sort(lca_pairs.begin(), lca_pairs.end(), [&](auto ll, auto rr) -> bool {
          return depth[ll] < depth[rr];
        });
        cout << (IsBad(query, lca_pairs.back()) ? 0 : 1);
      }
      cout << '\n';
    }
  }

  void Precompute() {
    depth.resize(n + 1);
    lg = int(log2(n)) + 1;
    par.assign(n + 1, vector<int>(lg + 1, 0));
    ranges.resize(n + 1);
    children_ranges.resize(n + 1);
    Dfs(1, 0, 0);
  }

  void Dfs(int u, int p, int d) {
    par[u][0] = p;
    depth[u] = d;
    ranges[u].first = ++timer;
    for (int i = 1; i <= lg; ++i) {
      par[u][i] = par[par[u][i - 1]][i - 1];
    }
    for (auto &v : graph[u]) {
      if (v != p) {
        Dfs(v, u, d + 1);
        children_ranges[u].push_back(ranges[v]);
      }
    }
    ranges[u].second = ++timer;
  }

  int GetDistance(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[GetLca(u, v)];
  }

  int GetLca(int u, int v) {
    if (depth[u] < depth[v]) {
      swap(u, v);
    }
    int depth_diff = depth[u] - depth[v];
    for (int i = 0; i <= lg; ++i) {
      if ((depth_diff >> i) & 1) {
        u = par[u][i];
      }
    }
    if (u == v) return u;
    for (int i = lg; i >= 0; --i) {
      if (par[u][i] != par[v][i]) {
        u = par[u][i];
        v = par[v][i];
      }
    }
    return par[u][0];
  }

  bool IsBad(vector<int> &query, int node) {
    set<int> components;
    for (auto &q : query) {
      if (q == node) return true;
      int time_q = ranges[q].first;
      if (ranges[node].first <= time_q && time_q <= ranges[node].second) {
        int ind = int(upper_bound(
                          children_ranges[node].begin(), 
                          children_ranges[node].end(),
                          make_pair(time_q, INT_MAX)
                     ) - children_ranges[node].begin()) - 1;
        components.insert(ind);
      } else {
        components.insert(-1);
      }
    }
    return int(components.size()) != int(query.size());
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}