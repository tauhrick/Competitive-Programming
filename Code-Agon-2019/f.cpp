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
  string s;
  cin >> s;
  int n = s.size();
  vector<int> d1(n);
  for (int i = 0, l = 0, r = -1; i < n; i++) {
    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
      k++;
    }
    d1[i] = k--;
    if (i + k > r) {
      l = i - k;
      r = i + k;
    }
  }
  vector<int> st(n);
  int l = 0;
  for (int i = 0; i < n; ++i) {
    while (l + (d1[l] - 1) < i) {
      ++l;
    }
    st[i] = 2 * (i - l) + 1;
  }
  for (int i = 1; i < n; ++i) {
    st[i] = max(st[i], st[i - 1]);
  }
  vector<int> en(n);
  int r = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    while (r - (d1[r] - 1) > i) {
      --r;
    }
    en[i] = 2 * (r - i) + 1;
  }
  for (int i = n - 2; i >= 0; --i) {
    en[i] = max(en[i], en[i + 1]);
  }
  long long res = LLONG_MIN;
  for (int i = 0; i + 1 < n; ++i) {
    res = max(res, 1LL * st[i] * en[i + 1]);
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
