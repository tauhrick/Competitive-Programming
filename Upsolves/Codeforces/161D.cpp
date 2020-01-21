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

const int N = 2.5e7;

void test_case() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> G(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  vector<vector<int>> cnt(n + 1, vector<int>(k + 1));
  function<void(int, int)> pre = [&](int u, int p) {
    for (auto v : G[u]) {
      if (v != p) {
        pre(v, u);
      }
    }
    cnt[u][0] = 1;
    for (int dep = 1; dep <= k; ++dep) {
      for (auto v : G[u]) {
        if (v != p) {
          cnt[u][dep] += cnt[v][dep - 1];
        }
      }
    }
  };
  pre(1, 0);
  long long res = 0;
  function<void(int, int)> dfs = [&](int u, int p) {
    res += cnt[u][k];
    for (int dep = 1; dep < k; ++dep) {
      int rem = k - dep;
      long long tot = 0;
      for (auto v : G[u]) {
        if (v != p) {
          tot += cnt[v][rem - 1];
        }
      }
      for (auto v : G[u]) {
        if (v != p)  {
          tot -= cnt[v][rem - 1];
          res += cnt[v][dep - 1] * tot;
        }
      }
    }
    for (auto v : G[u]) {
      if (v != p) {
        dfs(v, u);
      }
    }
  };
  dfs(1, 0);
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
