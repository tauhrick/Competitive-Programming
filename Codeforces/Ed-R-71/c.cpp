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
  int n, a, b;
  cin >> n >> a >> b;
  string S;
  cin >> S;
  int m = n + 1;
  vector<int> h(m);
  for (int i = 0; i < n; ++i) {
    if (S[i] == '0') {
      h[i] = max(h[i], 1);
      h[i + 1] = max(h[i + 1], 1);
    } else {
      h[i] = max(h[i], 2);
      h[i + 1] = max(h[i + 1], 2);
    }
  }
  vector<vector<long long>> dp(m, vector<long long>(3, -1));
  function<long long(int, int)> solve = [&](int ind, int prv) {
    if (ind == m - 1) {
      if (prv == 2) {
        return 2LL * a + b;
      } else {
        return 1LL * a + b;
      }
    }
    auto& ans = dp[ind][prv];
    if (ans == -1) {
      ans = LLONG_MAX;
      if (h[ind] == 2) {
        ans = (prv == 1 ? 2 : 1) * a + h[ind] * b + solve(ind + 1, h[ind]);
      } else {
        for (int curr = 1; curr <= 2; ++curr) {
          ans = min(ans, (prv != curr ? 2 : 1) * a + curr * b + solve(ind + 1, curr));
        }
      }
    }
    return ans;
  };
  cout << solve(1, 1) + b << "\n";
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
