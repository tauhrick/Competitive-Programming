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
  int m = n * n;
  vector<int> A(m);
  for (int i = 0; i < m; ++i) {
    cin >> A[i];
  }
  sort(A.rbegin(), A.rend());
  map<int, int> cnt;
  vector<int> res;
  int i = 0;
  while (i < m) {
    if (cnt[A[i]] == 0) {
      res.emplace_back(A[i]);
      for (int j = 0; j + 1 < (int) res.size(); ++j) {
        cnt[__gcd(res[j], A[i])] += 2;
      }
      ++i;
    } else {
      --cnt[A[i++]];
    }
  }
  assert((int) res.size() == n);
  for (int i = 0; i < n; ++i) {
    cout << res[i] << " \n"[i == n - 1];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
