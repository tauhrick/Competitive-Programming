#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

struct Query {
  int t, e, x;
};

class Task {
 private:
  int n;
  vector<vector<int>> graph;
  vector<int> a, b;
  int q;
  vector<Query> queries;
  vector<int> dep;
  vector<int64_t> lazy;

  void Read() {
    cin >> n;
    graph.resize(n + 1);
    a.resize(n);
    b.resize(n);
    for (int i = 1; i < n; ++i) {
      cin >> a[i] >> b[i];
      graph[a[i]].emplace_back(b[i]);
      graph[b[i]].emplace_back(a[i]);
    }
    cin >> q;
    queries.resize(q);
    for (auto &qq : queries) {
      cin >> qq.t >> qq.e >> qq.x;
    }
  }
 
  void Solve() {
    dep.resize(n + 1);
    Pre(1, 0, 0);
    lazy.resize(n + 1);
    int64_t offset = 0;
    for (auto qq : queries) {
      int va = a[qq.e], vb = b[qq.e];
      if (qq.t == 2) {
        swap(va, vb);
      }
      if (dep[va] > dep[vb]) {
        lazy[va] += qq.x;
      } else {
        lazy[vb] -= qq.x;
        offset += qq.x;
      }
    }
    Push(1, 0, 0);
    for (int i = 1; i <= n; ++i) {
      cout << lazy[i] + offset << "\n";
    }
  }

  void Pre(int u, int p, int d) {
    dep[u] = d;
    for (auto &v : graph[u]) {
      if (v == p) continue;
      Pre(v, u, d + 1);
    }
  }

  void Push(int u, int p, int64_t sum) {
    lazy[u] += sum;
    for (auto &v : graph[u]) {
      if (v == p) continue;
      Push(v, u, lazy[u]);
    }
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