#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int n, m;
  vector<int> p, h;
  vector<int64_t> sum_p;
  vector<vector<int>> graph;
 
  void Read() {
    cin >> n >> m;
    p.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> p[i];
    }
    h.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> h[i];
    }
    graph.resize(n + 1);
    for (int i = 1; i < n; ++i) {
      int u, v;
      cin >> u >> v;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
  }
 
  void Solve() {
    sum_p.resize(n + 1);
    cout << (Check(1, 0) ? "Yes" : "No") << "\n";
  }

  bool Check(int u, int par) {
    sum_p[u] = p[u];
    bool ok = true;
    int64_t sum_child_good = 0;
    int64_t sum_child_bad = 0;
    for (auto &v : graph[u]) {
      if (v == par) continue;
      ok = ok && Check(v, u);
      sum_p[u] += sum_p[v];
      sum_child_good += (sum_p[v] + h[v]) / 2;
      sum_child_bad += (sum_p[v] - h[v]) / 2;
    }
    if ((sum_p[u] + h[u]) % 2 == 1 || (sum_p[u] - h[u]) % 2 == 1) return false;
    int64_t curr_good = (sum_p[u] + h[u]) / 2;
    int64_t curr_bad = (sum_p[u] - h[u]) / 2;
    ok = ok && curr_good >= 0 && curr_bad >= 0;
    int64_t ded = min(curr_bad, int64_t(p[u]));
    curr_bad -= ded;
    p[u] -= int(ded);
    curr_good -= p[u];
    return ok && sum_child_good <= curr_good && sum_child_bad >= curr_bad;
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}