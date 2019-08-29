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
  int n;
  cin >> n;
  vector<vector<pair<int, int>>> G(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v, 1);
    G[v].emplace_back(u, -1);
  }
  vector<int> dp(n + 1);
  function<void(int, int, int)> pre = [&](int u, int p, int prv) {
    dp[u] = prv;
    for (auto [v, e] : G[u]) {
      if (v != p) {
        pre(v, u, (e == -1));
      }
    }
  };
  pre(1, 0, 0);
  int res = INT_MAX;
  vector<int> cities;
  function<void(int, int, int)> dfs = [&](int u, int p, int prv) {
    if (prv == res) {
      cities.emplace_back(u);
    } else if (prv < res) {
      res = prv;
      cities.clear();
      cities.emplace_back(u);
    }
    for (auto [v, e] : G[u]) {
      if (v != p) {
        if (e == -1) {
          dfs(v, u, prv - 1);
        } else {
          dfs(v, u, prv + 1);
        }
      }
    }
  };
  dfs(1, 0, accumulate(dp.begin() + 1, dp.end(), 0));
  sort(cities.begin(), cities.end());
  cout << res << "\n";
  for (auto c : cities) {
    cout << c << " ";
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
