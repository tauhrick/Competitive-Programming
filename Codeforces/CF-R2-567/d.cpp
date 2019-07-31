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
  int n;
  cin >> n;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  int q;
  cin >> q;
  vector<int> b(n + 1, -1);
  vector<pair<int, pair<int, int>>> queries(q);
  for (int quer = 0; quer < q; ++quer) {
    int typ;
    cin >> typ;
    int p = -1, x;
    if (typ == 1) {
      cin >> p >> x;
    } else {
      cin >> x;
    }
    queries[quer] = {typ, {p, x}};
  }
  reverse(queries.begin(), queries.end());
  int mx = -1;
  vector<bool> seen(n + 1);
  for (int i = 0; i < q; ++i) {
    auto [typ, foo] = queries[i];
    auto [p, x] = foo;
    if (typ == 1 && !seen[p]) {
      A[p] = max(x, mx);
      seen[p] = true;
    }
    if (typ == 2) {
      mx = max(mx, x);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!seen[i]) {
      A[i] = max(A[i], mx);
    }
  }
  for (int i = 1; i <= n; ++i) {
    cout << A[i] << " \n"[i == n];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
