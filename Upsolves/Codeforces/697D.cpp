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
  vector<vector<int>> G(n + 1);
  for (int i = 2; i <= n; ++i) {
    int p;
    cin >> p;
    G[p].emplace_back(i);
    G[i].emplace_back(p);
  }
  vector<int> sub_sz(n + 1);
  function<void(int, int)> pre = [&](int u, int p) {
    sub_sz[u] = 1;
    for (auto v : G[u]) {
      if (v != p) {
        pre(v, u);
        sub_sz[u] += sub_sz[v];
      }
    }
  };
  pre(1, 0);
  vector<double> exp_st(n + 1);
  function<void(int, int, double)> dfs = [&](int u, int p, double st) {
    exp_st[u] = st;
    double tot = 0;
    for (auto v : G[u]) {
      if (v != p) {
        tot += sub_sz[v] / 2.;
      }
    }
    for (auto v : G[u]) {
      if (v != p) {
        dfs(v, u, st + tot - (sub_sz[v] / 2.) + 1);
      }
    }
  };
  dfs(1, 0, 1);
  cout << fixed << setprecision(10);
  for (int i = 1; i <= n; ++i) {
    cout << exp_st[i] << " \n"[i == n];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
