#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int n, m;
  vector<vector<int>> graph;
  vector<int> dist;
  vector<vector<int>> dp;
 
  void Read() {
    cin >> n >> m;
    graph.resize(n + 1);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      graph[u].emplace_back(v);
    }
  }

  void Pre() {
    dist = vector(n + 1, INT_MAX);
    dist[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.emplace(0, 1);
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();
      d = -d;
      if (d > dist[u]) continue;
      for (auto &v : graph[u]) {
        if (d + 1 < dist[v]) {
          dist[v] = d + 1;
          pq.emplace(-dist[v], v);
        }
      }
    }
  }
 
  void Solve() {
    Pre();
    dp = vector(n + 1, vector(2, -1));
    for (int i = 1; i <= n; ++i) {
      cout << Travel(i, 0) << " \n"[i == n];
    }
  }

  int Travel(int u, int d) {
    auto &ans = dp[u][d];
    if (ans == -1) {
      ans = dist[u];
      for (auto &v : graph[u]) {
        if (dist[v] > dist[u]) {
          ans = min(ans, Travel(v, d));
        } else if (d == 0) {
          ans = min(ans, Travel(v, d + 1));
        }
      }
    }
    return ans;
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}