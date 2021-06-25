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
  string letters;
  vector<int> order;
  vector<int> dep;
  vector<int> tin;
  vector<int> tout;
  int timer;
  vector<vector<int>> pf;

  void Read() {
    cin >> n >> m; 
    graph.resize(n + 1);
    graph[0] = {1};
    for (int i = 2; i <= n; ++i) {
      int p;
      cin >> p;
      graph[p].push_back(i);
    }
    cin >> letters;
    letters = " " + letters;
  }
 
  void Solve() {
    Pre();
    while (m--) {
      int v, h;
      cin >> v >> h;
      int st = int(lower_bound(order.begin(), order.end(), h, [&](int el, int val) -> bool {
                                return dep[el] < val;
                              }) - order.begin());
      int en = int(upper_bound(order.begin(), order.end(), h, [&](int val, int el) -> bool {
                                return val < dep[el];
                              }) - order.begin()) - 1;
      int n_st = int(lower_bound(order.begin() + st, order.begin() + en + 1, tin[v], [&](int el, int val) -> bool {
                                  return tin[el] < val;
                                }) - order.begin());
      int n_en = int(upper_bound(order.begin() + st, order.begin() + en + 1, tout[v], [&](int val, int el) -> bool {
                                  return val < tout[el];
                                }) - order.begin()) - 1;
      cout << (n_en < n_st || Check(n_st, n_en) ? "Yes" : "No") << '\n';
    }
  }

  void Pre() {
    dep.resize(n + 1);
    int d = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int sz = int(q.size());
      while (sz--) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        dep[u] = d;
        for (auto &v : graph[u]) {
          q.push(v);
        }
      }
      ++d;
    }
    tin.resize(n + 1);
    tout.resize(n + 1);
    Dfs(0);
    pf = vector(n + 1, vector(26, 0));
    for (int i = 1; i <= n; ++i) {
      pf[i] = pf[i - 1];
      ++pf[i][int(letters[order[i]] - 'a')];
    }
  }

  void Dfs(int u) {
    tin[u] = ++timer;
    for (auto &v : graph[u]) {
      Dfs(v);
    }
    tout[u] = ++timer;
  }

  bool Check(int l, int r) {
    int odd = 0;
    for (int i = 0; i < 26; ++i) {
      odd += (pf[r][i] - pf[l - 1][i]) % 2 == 1;
    }
    return odd <= 1;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}