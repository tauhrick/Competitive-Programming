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
  vector<int> A(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  sort(A.begin() + 1, A.end());
  vector<vector<long long>> dp(n + 1, vector<long long>(k, LLONG_MAX));
  for (int ind = 1; ind <= n; ++ind) {
    for (int rem = 0; rem < k; ++rem) {
      auto& ans = dp[ind][rem];
      long long sum = 0;
      for (int i = ind - 1; i >= 1; --i) {
        if (rem > 0) {
          ans = min(ans, sum + dp[i][rem - 1]);
        }
        sum += A[ind] - A[i];
      }
      ans = min(ans, sum);
    }
  }
  cout << dp[n][k - 1] << "\n";
}
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
