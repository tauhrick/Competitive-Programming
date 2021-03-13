#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n;
  vector<int> s;
  int q;
  vector<pair<int, int>> queries;
  vector<int> sg_gcd;

  void Read() {
    cin >> n;
    s.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> s[i];
    }
    cin >> q;
    queries.resize(q);
    for (auto &i : queries) {
      cin >> i.first >> i.second;
    }
  }
 
  void Solve() {
    sg_gcd.resize(4 * n + 1);
    Build(1, 1, n);
    map<int, vector<int>> inds;
    for (int i = 1; i <= n; ++i) {
      inds[s[i]].push_back(i);
    }
    for (auto &[l, r] : queries) {
      int g = Get(1, 1, n, l, r);
      int g_cnt = int(upper_bound(inds[g].begin(), inds[g].end(), r) -
                      lower_bound(inds[g].begin(), inds[g].end(), l));
      cout << r - l + 1 - g_cnt << '\n';
    }
  }

  void Build(int tv, int tl, int tr) {
    if (tl == tr) {
      sg_gcd[tv] = s[tl];
    } else {
      int tm = (tl + tr) >> 1, lc = 2 * tv, rc = lc + 1;
      Build(lc, tl, tm);
      Build(rc, tm + 1, tr);
      sg_gcd[tv] = gcd(sg_gcd[lc], sg_gcd[rc]);
    }
  }

  int Get(int tv, int tl, int tr, int ql, int qr) {
    if (qr < tl || ql > tr) {
      return 0;
    } else if (ql <= tl && tr <= qr) {
      return sg_gcd[tv];
    } else {
      int tm = (tl + tr) >> 1, lc = 2 * tv, rc = lc + 1;
      return gcd(Get(lc, tl, tm, ql, qr), Get(rc, tm + 1, tr, ql, qr));
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}