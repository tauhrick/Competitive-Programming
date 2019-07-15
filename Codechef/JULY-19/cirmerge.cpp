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

const int N = 410;

int n;
int A[2 * N];
long long pre[2 * N];
long long dp[N][N];

long long solve(int l, int len) {
  if (len == 1) {
    return 0LL;
  }
  auto& ans = dp[l][len];
  if (ans == -1) {
    ans = LLONG_MAX;
    long long tot = pre[l + len - 1] - pre[l - 1];
    for (int take = 1; take < len; ++take) {
      int nxt = l + take;
      if (nxt > n) {
        nxt -= n;
      }
      ans = min(ans, tot + solve(l, take) + solve(nxt, len - take));
    }
  }
  return ans;
}

void test_case() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  for (int i = 1; i <= n; ++i) {
    A[n + i] = A[i];
  }
  for (int i = 1; i < 2 * n; ++i) {
    pre[i] = pre[i - 1] + A[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      dp[i][j] = -1;
    }
  }
  long long res = LLONG_MAX;
  for (int st = 1; st <= n; ++st) {
    res = min(res, solve(st, n));
  }
  cout << res << "\n";
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
