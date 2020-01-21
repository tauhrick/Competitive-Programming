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
  vector<int> C(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> C[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  function<int(int, int)> solve = [&](int l, int r) {
    if (l > r) {
      return 0;
    } else if (r == l) {
      return 1;
    }
    auto& ans = dp[l][r];
    if (ans == -1) {
      ans = 1 + solve(l + 1, r);
      for (int k = l + 1; k <= r; ++k) {
        if (C[l] == C[k]) {
          if (k == l + 1) {
            ans = min(ans, 1 + solve(k + 1, r));
          } else {
            ans = min(ans, solve(l + 1, k - 1) + solve(k + 1, r));
          }
        }
      }
    }
    return ans;
  };
  cout << solve(1, n) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
