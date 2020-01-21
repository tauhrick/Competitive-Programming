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
  vector<int> cost(m + 1);
  vector<vector<int>> locks(m + 1);
  for (int i = 1; i <= m; ++i) {
    int a, b;
    cin >> a >> b;
    cost[i] = a;
    locks[i].resize(b);
    for (auto& l : locks[i]) {
      cin >> l;
      --l;
    }
  }
  const long long LIM = 1e12;
  const int TAR = (1 << n) - 1;
  vector<vector<long long>> dp(m + 1, vector<long long>(1 << n, -1));
  function<long long(int, int)> solve = [&](int ind, int mask) {
    if (ind == m + 1) {
      return (mask == TAR ? 0 : LIM);
    }
    auto& ans = dp[ind][mask];
    if (ans == -1) {
      ans = LLONG_MAX;
      ans = min(ans, solve(ind + 1, mask));
      for (auto& l : locks[ind]) {
        mask |= 1 << l;
      }
      ans = min(ans, cost[ind] + solve(ind + 1, mask));
    }
    return ans;
  };
  long long ans = solve(1, 0);
  if (ans >= LIM) {
    ans = -1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
