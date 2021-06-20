#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kA = int(2.0e5);

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n;
  vector<int> a; 
  vector<vector<int>> graph;
  vector<bool> seen;
  int cc;

  void Read() {
    cin >> n;
    a.resize(n); 
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    graph.resize(kA + 1);
    for (int i = 0; i < n; ++i) {
      graph[a[i]].push_back(a[n - i - 1]);
      graph[a[n - i - 1]].push_back(a[i]);
    }
    seen.resize(kA + 1);
    int res = 0;
    for (int i = 1; i <= kA; ++i) {
      if (!seen[i]) {
        cc = 0;
        Dfs(i);
        res += cc - 1;
      }
    }
    cout << res << '\n';
  }

  void Dfs(int u) {
    seen[u] = true;
    ++cc;
    for (auto &v : graph[u]) {
      if (!seen[v]) {
        Dfs(v);
      }
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}