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
  int n, m;
  vector<int> a;
  vector<int> b;
  vector<int> c;

  void Read() {
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    b.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> b[i];
    }
    c.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
      cin >> c[i];
    }
  }
 
  void Solve() {
    vector<set<int>> req(n + 1);
    vector<int> col(n + 1, -1);
    for (int i = 1; i <= n; ++i) {
      if (b[i] != a[i]) {
        req[b[i]].insert(i);
      }
      col[b[i]] = i;
    }
    vector<int> inds(m + 1);
    for (int i = m; i >= 1; --i) {
      if (req[c[i]].empty()) {
        if (i == m) {
          if (col[c[i]] == -1) {
            cout << "NO\n";
            return;
          } else {
            inds[i] = col[c[i]];
          }
        } else {
          inds[i] = inds[m];
        }
      } else {
        inds[i] = *req[c[i]].begin();
        req[c[i]].erase(req[c[i]].begin());
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (!req[i].empty()) {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
    for (int i = 1; i <= m; ++i) {
      cout << inds[i] << " \n"[i == m];
      a[inds[i]] = c[i];
    }
    assert(a == b);
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}