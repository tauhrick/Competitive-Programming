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

const int N = 1e3 + 10;

int n, m;
int A[N][N];
int dp1[N][N];
int dp2[N][N];
int dp3[N][N];
int dp4[N][N];

int solve1(int r, int c) {
  auto& ans = dp1[r][c];
  if (ans == -1) {
    ans = A[r][c];
    int to_add = 0;
    if (c - 1 >= 1) {
      to_add = max(to_add, solve1(r, c - 1));
    }
    if (r - 1 >= 1) {
      to_add = max(to_add, solve1(r - 1, c));
    }
    ans += to_add;
  }
  return ans;
}

int solve2(int r, int c) {
  auto& ans = dp2[r][c];
  if (ans == -1) {
    ans = A[r][c];
    int to_add = 0;
    if (c + 1 <= m) {
      to_add = max(to_add, solve2(r, c + 1));
    }
    if (r - 1 >= 1) {
      to_add = max(to_add, solve2(r - 1, c));
    }
    ans += to_add;
  }
  return ans;
}

int solve3(int r, int c) {
  auto& ans = dp3[r][c];
  if (ans == -1) {
    ans = A[r][c];
    int to_add = 0;
    if (c + 1 <= m) {
      to_add = max(to_add, solve3(r, c + 1));
    }
    if (r + 1 <= n) {
      to_add = max(to_add, solve3(r + 1, c));
    }
    ans += to_add;
  }
  return ans;
}

int solve4(int r, int c) {
  auto& ans = dp4[r][c];
  if (ans == -1) {
    ans = A[r][c];
    int to_add = 0;
    if (c - 1 >= 1) {
      to_add = max(to_add, solve4(r, c - 1));
    }
    if (r + 1 <= n) {
      to_add = max(to_add, solve4(r + 1, c));
    }
    ans += to_add;
  }
  return ans;
}

void test_case() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      cin >> A[i][j];
    }
  }
  memset(dp1, -1, sizeof dp1);
  memset(dp2, -1, sizeof dp2);
  memset(dp3, -1, sizeof dp3);
  memset(dp4, -1, sizeof dp4);
  int res = INT_MIN;
  for (int i = 2; i < n; ++i) {
    for (int j = 2; j < m; ++j) {
      res = max(res, solve1(i, j - 1) + solve2(i - 1, j) + solve3(i, j + 1) + solve4(i + 1, j));
      res = max(res, solve1(i - 1, j) + solve2(i, j + 1) + solve3(i + 1, j) + solve4(i, j - 1));
    }
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
