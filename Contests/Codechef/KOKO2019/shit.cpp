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

const int N = 25;

bool dp[N][N][N];
bool seen[N][N][N];

void test_case() {
  int n;
  cin >> n;
  vector<string> v(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
    v[i] = " " + v[i];
  }
  int m;
  string s;
  cin >> m >> s;
  function<bool(int, int, int)> solve = [&](int r, int c, int ind) {
    auto& ans = dp[r][c][ind];
    auto& vis = seen[r][c][ind];
    if (!vis) {
      vis = true;
      if (ind == m - 1) {
        ans = true;
      } else {
        if (r + 1 <= n && v[r + 1][c] == s[ind + 1] && solve(r + 1, c, ind + 1)) {
          ans = true;
        } else if (c + 1 <= n && v[r][c + 1] == s[ind + 1] && solve(r, c + 1, ind + 1)) {
          ans = true;
        } else if (r + 1 <= n && c + 1 <= n && v[r + 1][c + 1] == s[ind + 1] && solve(r + 1, c + 1, ind + 1)) {
          ans = true;
        }
      }
    }
    return ans;
  };
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (v[i][j] == s[0] && solve(i, j, 0)) {
        cout << "Yes\n";
        return;
      }
    }
  }
  cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
