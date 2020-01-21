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

using ll = long long;

const int N = 1010, P = N;
const ll inf = LLONG_MAX;

struct point {
  ll m, c; // y = mx + c
  point() : m(0), c(inf) {} // ### (inf -> -inf)
  point(ll _m, ll _c) : m(_m), c(_c) {}
};
 
point line[4 * P];
 
struct li_chao_tree {
  void add_line(point add, int i = 1, ll l = 0, ll r = P) {
    ll m = (l + r) / 2;
    bool lef = (eval(add, l) < eval(line[i], l)); // ###
    bool mid = (eval(add, m) < eval(line[i], m)); // ###
    if (mid) {
      swap(add, line[i]);
    }
    if (l == r - 1) { // Leaf Node
      return;
    } else if (lef != mid) { // Intersection point in [l, m)
      add_line(add, 2 * i, l, m);
    } else { // Intersection point in [m, r)
      add_line(add, 2 * i + 1, m, r);
    }
  }
  ll query(ll x, int i = 1, ll l = 0, ll r = P) {
    ll ans = eval(line[i], x), m = (l + r) / 2;
    if (l == r - 1) {
      return ans;
    } else if (x < m) {
      return min(ans, query(x, 2 * i, l, m)); // ###
    } else {
      return min(ans, query(x, 2 * i + 1, m, r)); // ###
    }
  }
  ll eval(point p, ll x) {
    return p.m * x + p.c;
  }
  void clear(int i = 1, ll l = 0, ll r = P) {
    ll m = (l + r) / 2;
    if (line[i].m == 0  and line[i].c == inf) {
      return;
    } else if (l == r - 1) {
      line[i] = {0, inf};
    } else {
      line[i] = {0, inf};
      clear(2 * i, l, m);
      clear(2 * i + 1, m, r);
    }
  }
} lct;

int n, z;
int a[N];

void test_case() {
  cin >> n >> z;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n);
  vector<vector<long long>> dp(n + 1, vector<long long>(z + 1, LLONG_MAX));
  for (int rem = 0; rem <= z; ++rem) {
    for (int st = 0; st <= n; ++st) {
      auto& ans = dp[st][rem];
      if (rem == 0) {
        ans = 0;
        continue;
      }
      int en = st - 1;
      if (en >= rem - 1) {
        lct.add_line({a[en + 1], dp[en][rem - 1] - a[en + 1] * en});
      }
      ans = lct.query(st);
    }
    lct.clear();
  }
  cout << dp[n][z] << "\n";
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

//~ Attribution: https://codeforces.com/contest/1179/submission/55926534
