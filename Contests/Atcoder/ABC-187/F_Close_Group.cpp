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
  vector<int> mask_graph;
  int kFull;
  vector<int> st;
  vector<int> dp;
  vector<bool> valid;

  void Read() {
    cin >> n >> m;
    kFull = (1 << n) - 1;
    graph.resize(n);
    mask_graph.resize(n);
    for (int i = 0; i < m; ++i) {
      int u, v;
      cin >> u >> v;
      --u, --v;
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
      mask_graph[u] |= (1 << v);
      mask_graph[v] |= (1 << u);
    }
  }
 
  void Solve() {
    Pre();
    dp = vector(kFull, INT_MAX);
    cout << Get(0) << "\n";
  }

  void Pre() {
    st.resize(kFull);
    for (int i = 0; i < kFull; ++i) {
      for (int j = 0; j < n; ++j) {
        if ((i >> j) % 2 == 0) {
          st[i] = j;
          break;
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      mask_graph[i] |= (1 << i);
    }
    valid.resize(kFull + 1);
    for (int i = 0; i <= kFull; ++i) {
      valid[i] = true;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          valid[i] = valid[i] && ((i & mask_graph[j]) == i);
        }
      }
    }
  }

  int Get(int mask) {
    if (mask == kFull) {
      return 0;
    }
    auto &ans = dp[mask];
    if (ans == INT_MAX) {
      int u = st[mask];
      vector<int> rem;
      for (auto &v : graph[u]) {
        if ((mask >> v) % 2 == 0) {
          rem.emplace_back(v);
        }
      }
      int en = 1 << int(rem.size());
      for (int i = 0; i < en; ++i) {
        int or_mask = (1 << u);
        for (int j = 0; j < int(rem.size()); ++j) {
          if ((i >> j) & 1) {
            or_mask |= (1 << rem[j]);
          }
        }
        if (valid[or_mask]) {
          ans = min(ans, 1 + Get(mask | or_mask));
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
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  Task t;
  t.Perform();
  return 0;
}