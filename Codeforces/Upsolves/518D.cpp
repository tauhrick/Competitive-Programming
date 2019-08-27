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
  int n, t;
  double p;
  cin >> n >> p >> t;
  vector<vector<double>> dp(t + 1, vector<double>(n + 1));
  vector<vector<int>> seen(t + 1, vector<int>(n + 1));
  function<double(int, int)> solve = [&](int ctr, int taken) {
    if (ctr == t + 1 || taken == n) {
      return 1. * taken;
    }
    auto& ans = dp[ctr][taken];
    auto& vis = seen[ctr][taken];
    if (!vis) {
      vis = true;
      ans = 0;
      ans += p * solve(ctr + 1, taken + 1);
      ans += (1 - p) * solve(ctr + 1, taken);
    }
    return ans;
  };
  cout << fixed << setprecision(10) << solve(1, 0) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
