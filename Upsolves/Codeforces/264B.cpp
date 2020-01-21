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

const int N = 1e5 + 10;

vector<int> min_fact(N + 1);

void pre() {
  min_fact[1] = 1;
  for (int i = 2; i <= N; ++i) {
    if (!min_fact[i]) {
      for (int j = i; j <= N; j += i) {
        if (!min_fact[j]) {
          min_fact[j] = i;
        }
      }
    }
  }
}

void test_case() {
  int n;
  cin >> n;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  vector<int> prv(N + 1, -1);
  vector<int> dp(n + 1);
  for (int i = 1; i <= n; ++i) {
    int num = A[i];
    int to_add = 0;
    while (num != 1) {
      int f = min_fact[num];
      while (num % f == 0) {
        num /= f;
      }
      if (prv[f] != -1) {
        to_add = max(to_add, prv[f]);
      }
    }
    dp[i] = 1 + to_add;
    num = A[i];
    while (num != 1) {
      int f = min_fact[num];
      while (num % f == 0) {
        num /= f;
      }
      prv[f] = max(prv[f], dp[i]);
    }
  }
  cout << *max_element(dp.begin() + 1, dp.end()) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  pre();
  test_case();
  return 0;
}
