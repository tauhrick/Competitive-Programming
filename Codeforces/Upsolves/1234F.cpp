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

const int N = 20, M = 1 << N;

void test_case() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> mx_len(M);
  for (int i = 0; i < n; ++i) {
    int mask = 0;
    for (int j = i; j < n; ++j) {
      int bit = (s[j] - 'a');
      if (mask & (1 << bit)) {
        break;
      } else {
        mask |= (1 << bit);
        mx_len[mask] = __builtin_popcount(mask);
      }
    }
  }
  for (int i = 0; i < M; ++i) {
    for (int j = 0; j < N; ++j) {
      if (i & (1 << j)) {
        mx_len[i] = max(mx_len[i], mx_len[i ^ (1 << j)]);
      }
    }
  }
  int res = 0;
  for (int i = 0; i < M; ++i) {
    res = max(res, mx_len[i] + mx_len[i ^ (M - 1)]);
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
