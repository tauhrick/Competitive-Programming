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
  int n, k;
  cin >> n >> k;
  vector<vector<int>> perm(k + 1, vector<int>(n + 1));
  map<pair<int, int>, int> pos;
  for (int p = 1; p <= k; ++p) {
    for (int i = 1; i <= n; ++i) {
      cin >> perm[p][i];
      pos[{p, perm[p][i]}] = i;
    }
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
  function<int(int, int)> solve = [&](int ind, int prv) {
    if (ind == n + 1) {
      return 1;
    }
    auto& ans = dp[ind][prv];
    if (ans == -1) {
      ans = solve(ind + 1, prv);
      int el = perm[1][ind];
      bool ok = true;
      for (int p = 2; p <= k; ++p) {
        if (pos[{p, el}] < pos[{p, prv}]) {
          ok = false;
        }
      }
      if (ok) {
        ans = max(ans, 1 + solve(ind + 1, el));
      }
    }
    return ans;
  };
  cout << solve(1, 0) - 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
