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

const int N = 1e6 + 10;

long long sg[4 * N + 4];

void modify(int p, long long v, int tv = 1, int tl = 1, int tr = N) {
  if (tl == tr) {
    sg[tv] = min(sg[tv], v);
  } else {
    int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
    if (p <= tm) {
      modify(p, v, lc, tl, tm);
    } else {
      modify(p, v, rc, tm + 1, tr);
    }
    sg[tv] = min(sg[lc], sg[rc]);
  }
}

long long get(int ql, int qr, int tv = 1, int tl = 1, int tr = N) {
  if (qr < tl || ql > tr) {
    return LLONG_MAX;
  } else if (ql <= tl && tr <= qr) {
    return sg[tv];
  } else {
    int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
    return min(get(ql, qr, lc, tl, tm), get(ql, qr, rc, tm + 1, tr));
  }
}

void test_case() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  set<long long> one;
  vector<long long> ab(n + 1);
  for (int i = n; i >= 1; --i) {
    auto it = one.upper_bound(a[i]);
    if (it != one.end()) {
      ab[i] = a[i] * (*it);
    } else {
      ab[i] = -1;
    }
    one.insert(a[i]);
  }
  fill(sg, sg + 4 * N + 4, LLONG_MAX);
  long long ans = LLONG_MAX;
  for (int i = n; i >= 1; --i) {
    long long mn = get(a[i] + 1, N);
    if (mn != LLONG_MAX) {
      ans = min(ans, a[i] * mn);
    }
    if (ab[i] != -1) {
      modify(a[i], ab[i]);
    }
  }
  if (ans == LLONG_MAX) {
    ans = -1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
