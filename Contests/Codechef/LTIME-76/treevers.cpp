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

const int N = 1e5 + 10;

int n;
int w[N];
int zero[N], one[N];
vector<int> G[N];
vector<int> g[N];
vector<int> order;

void clear_data() {
  for (int i = 1; i <= n; ++i) {
    w[i] = zero[i] = one[i] = 0;
    G[i].clear();
    g[i].clear();
  }
  order.clear();
}

void dfs_pre(int u, int p = -1) {
  if (w[u] == 0) {
    ++zero[u];
  } else {
    ++one[u];
  }
  for (auto v : G[u]) {
    if (v != p) {
      dfs_pre(v, u);
      zero[u] += zero[v];
      one[u] += one[v];
      g[u].emplace_back(v);
    }
  }
}

void dfs(int u) {
  order.emplace_back(w[u]);
  for (auto v : g[u]) {
    dfs(v);
  }
}

void test_case() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
  }
  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  dfs_pre(1);
  for (int i = 1; i <= n; ++i) {
    sort(g[i].begin(), g[i].end(), [&](int a, int b) {
      return (1LL * one[a] * zero[b]) < (1LL * one[b] * zero[a]);
    });
  }
  dfs(1);
  long long inv_count = 0;
  int zero_cnt = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (order[i] == 1) {
      inv_count += zero_cnt;
    } else {
      ++zero_cnt;
    }
  }
  cout << inv_count << "\n";
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
