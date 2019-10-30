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
  vector<int> P(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> P[i];
  }
  vector<vector<int>> G(n + 1);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  vector<bool> seen(n + 1);
  vector<int> indices;
  vector<int> values;
  function<void(int)> dfs = [&](int u) {
    seen[u] = true;
    indices.emplace_back(u);
    values.emplace_back(P[u]);
    for (auto v : G[u]) {
      if (!seen[v]) {
        dfs(v);
      }
    }
  };
  vector<int> res(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (!seen[i]) {
      indices.clear();
      values.clear();
      dfs(i);
      sort(values.rbegin(), values.rend());
      sort(indices.begin(), indices.end());
      for (int j = 0; j < (int) indices.size(); ++j) {
        res[indices[j]] = values[j];
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << res[i] << " \n"[i == n];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
