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

const int N = 1e4 + 10, LG = log2(N) + 2;

int n;
vector<vector<pair<int, int>>> G(N);
vector<vector<int>> up(N, vector<int>(LG));
vector<long long> dist(N);
vector<int> dep(N);

void clear_data() {
  for (int i = 1; i <= n; ++i) {
    G[i].clear();
    dist[i] = dep[i] = 0;
  }
}

void dfs(int u, int p, long long prv, int d) {
  up[u][0] = p;
  dist[u] = prv;
  dep[u] = d;
  for (auto nxt : G[u]) {
    int v = nxt.first, w = nxt.second;
    if (v != p) {
      dfs(v, u, prv + w, d + 1);
    }
  }
}

int lca(int u, int v) {
  if (dep[u] < dep[v]) {
    swap(u, v);
  }
  int diff = dep[u] - dep[v];
  for (int i = 0; i < LG; ++i) {
    if (diff & (1 << i)) {
      u = up[u][i];
    }
  }
  if (u == v) {
    return u;
  }
  for (int i = LG - 1; i >= 0; --i) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

int kth_ancestor(int u, int k) {
  for (int i = 0; i < LG; ++i) {
    if (k & (1 << i)) {
      u = up[u][i];
    }
  }
  return u;
}

void test_case() {
  cin >> n;
  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    G[u].emplace_back(v, w);
    G[v].emplace_back(u, w);
  }
  dfs(1, 0, 0, 0);
  for (int k = 1; k < LG; ++k) {
    for (int i = 1; i <= n; ++i) {
      up[i][k] = up[up[i][k - 1]][k - 1];
    }
  }
  string quer;
  while (cin >> quer, quer != "DONE") {
    int a, b;
    cin >> a >> b;
    int lca_node = lca(a, b);
    if (quer == "DIST") {
      cout << dist[a] + dist[b] - 2 * dist[lca_node] << "\n";
    } else {
      int k;
      cin >> k;
      if (dep[a] - dep[lca_node] >= k - 1) {
        cout << kth_ancestor(a, k - 1) << "\n";
      } else {
        int dep_a = dep[a] - dep[lca_node];
        int dep_b = dep[b] - dep[lca_node];
        int rem = k - dep_a - 1;
        int lift = dep_b - rem;
        cout << kth_ancestor(b, lift) << "\n";
      }
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    test_case();
    if (tt != tc) {
      clear_data();
    }
  }
  return 0;
}
