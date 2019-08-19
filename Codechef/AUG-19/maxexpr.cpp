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
  vector<double> K(n + 1), C(n + 1);
  double den = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> K[i];
    den += 1 / K[i];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> C[i];
  }
  double p = 0;
  for (int i = 1; i <= n; ++i) {
    p += K[i] * C[i];
  }
  if (p < 0) {
    cout << "-1\n";
    return;
  }
  vector<double> X(n + 1);
  double f = 0;
  for (int i = 1; i <= n; ++i) {
    double t = p / (den * K[i] * K[i]);
    f += sqrt(t);
    X[i] = t - C[i];
  }
  cout << f << " ";
  for (int i = 1; i <= n; ++i) {
    cout << X[i] << " \n"[i == n];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(10);
  int tc;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
