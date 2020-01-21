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
  long long a, b, c;
  cin >> a >> b >> c;
  auto get = [&](auto x, auto y, auto z) {
    long long p = y, q = z;
    long long add = abs(p - q);
    if (add <= x) {
      if (p < q) {
        p += add;
      } else {
        q += add;
      }
      x -= add;
      p += x / 2;
      q += x / 2;
      return p + q;
    } else {
      return 2 * min(p, q);
    }
  };
  long long ans = max({get(a, b, c), get(b, a, c), get(c, a, b)});
  cout << ans / 2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    test_case();
  }
  return 0;
}
