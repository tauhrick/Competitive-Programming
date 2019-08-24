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

const int INF = 1e7;

void test_case() {
  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<string> grid(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> grid[i];
    grid[i] = " " + grid[i];
  }
  vector<int> cnt(m + 1);
  for (int c = 1; c <= m; ++c) {
    for (int r = 1; r <= n; ++r) {
      cnt[c] += (grid[r][c] == '#');
    }
  }
  vector<vector<vector<int>>> dp(m + 1, vector<vector<int>>(m + 1, vector<int>(2, -1)));
  function<int(int, int, int)>solve = [&](int prv, int ind, int st) {
    int len = ind - prv + 1;
    int curr = (st == 1 ? n - cnt[ind] : cnt[ind]);
    if (ind == m) {
      if (x <= len && len <= y) {
        return curr;
      } else {
        return INF;
      }
    }
    auto& ans = dp[prv][ind][st];
    if (ans == -1) {
      ans = curr;
      int to_add = INF;
      if (x <= len && len <= y) {
        to_add = solve(ind + 1, ind + 1, st ^ 1);
      }
      to_add = min(to_add, solve(prv, ind + 1, st));
      ans += to_add;
    }
    return ans;
  };
  cout << min(solve(1, 1, 0), solve(1, 1, 1)) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
