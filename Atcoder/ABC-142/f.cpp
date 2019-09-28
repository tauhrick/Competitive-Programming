#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

void test_case() {
  int n, m;
  cin >> n >> m;
  vector<set<int>> G(n + 1);
  vector<pair<int, int>> edges(m + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].insert(v);
    edges[i] = {u, v};
  }
  for (int i = 1; i <= m; ++i) {
    int u = edges[i].first;
    int v = edges[i].second;
    G[u].erase(v);
    vector<int> par(n + 1, -1);
    debug(i);
    function<void(int, int)> dfs = [&](int u, int p) {
      debug(u, p);
      par[u] = p;
      for (auto v : G[u]) {
        if (par[v] == -1) {
          dfs(v, u);
        }
      }
    };
    dfs(v, 0);
    if (par[u] != -1) {
      set<int> nodes;
      int curr = u;
      while (curr != 0) {
        nodes.insert(curr);
        curr = par[curr];
      }
      vector<int> in_deg(n + 1), out_deg(n + 1);
      for (int i = 1; i <= m; ++i) {
        int _u = edges[i].first;
        int _v = edges[i].second;
        if (nodes.count(_u) && nodes.count(_v)) {
          ++in_deg[_v];
          ++out_deg[_u];
        }
      }
      bool ok = true;
      for (auto node : nodes) {
        if (in_deg[node] == 1 && out_deg[node] == 1) {
        } else {
          ok = false;
        }
      }
      if (ok) {
        cout << nodes.size() << "\n";
        for (auto node : nodes) {
          cout << node << "\n";
        }
        return;
      }
    }
    G[u].insert(v);
  }
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
