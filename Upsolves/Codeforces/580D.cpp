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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  map<pair<int, int>, int> rules;
  for (int i = 1; i <= k; ++i) {
    int x, y, c;
    cin >> x >> y >> c;
    rules[{x, y}] = c;
  }
  vector<vector<long long>> dp(n + 1, vector<long long>(1 << n, -1));
  function<long long(int, int)> solve = [&](int prv, int mask) {
    if (__builtin_popcount(mask) == m) {
      return 0LL;
    }
    auto& ans = dp[prv][mask];
    if (ans == -1) {
      for (int i = 0; i < n; ++i) {
        if ((mask & (1 << i)) == 0) {
          int extra = (rules.count({prv, i + 1}) ? rules[{prv, i + 1}] : 0);
          ans = max(ans, A[i + 1] + solve(i + 1, mask | (1 << i)) + extra);
        }
      }
    }
    return ans;
  };
  cout << solve(0, 0) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
