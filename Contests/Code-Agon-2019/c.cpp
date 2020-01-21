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
  auto get_ans = [&](int x) {
    bool taken = false;
    int res = 0;
    int prv_cand = INT_MIN;
    for (int bit = 30; bit >= 0; --bit) {
      if (n & (1 << bit)) {
        if (!taken) {
          res += bit;
          if (bit >= 2) {
            prv_cand = bit + bit - 1;
          }
          taken = true;
        }
        ++res;
      }
    }
    return max(res, prv_cand);
  };
  int ans = get_ans(n);
  for (int bit = 30; bit >= 1; --bit) {
    if (n & (1 << bit)) {
      for (int on = bit - 1; on >= 1; --on) {
        if (n & (1 << on)) {
          n ^= (1 << on);
          for (int i = on - 1; i >= 0; --i) {
            n |= (1 << i);
          }
          break;
        }
      }
      break;
    }
  }
  ans = max(ans, get_ans(n));
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
