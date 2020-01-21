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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> A(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  long long res = 0;
  for (int st = 1; st <= m; ++st) {
    vector<long long> b;
    vector<vector<int>> buckets;
    for (int i = st; i <= n; ) {
      int rem = m;
      long long to_add = 0;
      vector<int> to_push;
      while (rem > 0 && i <= n)  {
        to_add += A[i];
        to_push.emplace_back(A[i]);
        i++;
        rem--;
      }
      b.emplace_back(to_add - k);
      buckets.emplace_back(to_push);
    }
    long long curr = 0;
    for (int i = 0; i < (int) b.size(); ++i) {
      long long en_sum = -k;
      for (int j = 0; j < (int) buckets[i].size(); ++j) {
        en_sum += buckets[i][j];
        res = max({res, curr + en_sum, en_sum});
      }
      curr = max(b[i], curr + b[i]);
      res = max(res, curr);
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
