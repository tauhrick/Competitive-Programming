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
  int k, q;
  cin >> k >> q;
  if (k == 2) {
    while (q--) {
      long long n, m;
      cin >> n >> m;
      if (n == 1) {
        cout << m << "\n";
      } else if (n == 2) {
        cout << "Thrown off the roof.\n";
      } else if (n == 3) {
        cout << m << "\n";
      } else {
        long long lo = 1, hi = n, mid;
        while (lo < hi) {
          mid = lo + (hi - lo + 1 >> 1);
          long long req = mid / k;
          long long rem = (mid & 1 ? m - req - 1 : m - req);
          if (rem >= 0) {
            lo = mid;
          } else {
            hi = mid - 1;
          }
        }
        if (lo >= n) {
          long long req = n / k;
          long long rem = (n & 1 ? m - req - 1 : m - req);
          cout << rem << "\n";
        } else {
          long long diff = n - lo + 1;
          int lg = log2(diff);
          if ((1ll << lg) == diff) {
            long long req = lo / k;
            long long rem = (lo & 1 ? m - req - 1 : m - req);
            cout << rem << "\n";
          } else {
            cout << "Thrown off the roof.\n";
          }
        }
      }
    }
  } else {
    vector<long long> pre;
    pre.reserve(3000000);
    long long prv = -1;
    while (prv < 1e18) {
      long long y = prv + 2;
      long long hi = y + y / (k - 1);
      long long lo = hi - 1;
      if (lo - lo / k == y) {
        pre.emplace_back(lo + 1);
        prv = lo;
      } else {
        pre.emplace_back(hi + 1);
        prv = hi;
      }
    }
    while (q--) {
      long long n, m;
      cin >> n >> m;
      long long req = n / k;
      long long rem = m - req;
      if (rem >= 0) {
        cout << rem << "\n";
      } else {
        long long lo = m * k + k - 1;
        long long diff = n - lo;
        if (binary_search(pre.begin(), pre.end(), diff)) {
          cout << 0 << "\n";
        } else {
          cout << "Thrown off the roof.\n";
        }
      }
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
