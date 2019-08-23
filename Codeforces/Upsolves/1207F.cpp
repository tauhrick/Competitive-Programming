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

const int N = 5e5 + 1, M = sqrt(N);

void test_case() {
  int q;
  cin >> q;
  vector<long long> A(N);
  vector<vector<long long>> dp(M, vector<long long>(M));
  while (q--) {
    int typ, x, y;
    cin >> typ >> x >> y;
    if (typ == 1) {
      A[x] += y;
      for (int i = 1; i < M; ++i) {
        dp[i][x % i] += y;
      }
    } else {
      long long sum = 0;
      if (x >= M) {
        for (int i = y; i < N; i += x) {
          sum += A[i];
        }
      } else {
        sum = dp[x][y];
      }
      cout << sum << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
