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
  vector<int> a;
  vector<vector<int64_t>> pf, sf_min;

  void Read() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
  }
 
  void Solve() {
    Prepare();
    if (Good()) {
      cout << "YES\n";
      return;
    }
    for (int i = 1; i + 1 <= n; ++i) {
      int d = 2 * (a[i + 1] - a[i]);
      int par = i & 1, rev = !par;
      if (pf[rev][i - 1] < 0) break;
      if (a[i + 1] - pf[rev][i - 1] >= 0 &&
          a[i] - a[i + 1] + pf[rev][i - 1] >= 0 &&
          GetSfMin(par, i + 2) >= -d &&
          GetSfMin(rev, i + 3) >= d &&
          pf[n & 1][n] + ((n & 1) == par ? d : -d) == 0) {
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
  }
  
  bool Good() {
    bool ok = (pf[n & 1][n] == 0);
    for (int i = 1; i <= n; ++i) {
      ok &= pf[i & 1][i] >= 0;
    }
    return ok;
  }

  void Prepare() {
    pf = vector(2, vector(n + 1, int64_t(INT64_MAX)));
    pf[0][0] = pf[1][0] = 0;
    for (int i = 1; i <= n; ++i) {
      int par = i & 1, rev = !par;
      pf[par][i] = a[i] - pf[rev][i - 1];
    }
    sf_min = vector(2, vector(n + 2, INT64_MAX));
    for (int i = n; i >= 1; --i) {
      for (auto j : {0, 1}) {
        sf_min[j][i] = min(sf_min[j][i + 1], pf[j][i]);
      }
    }
  }
  
  int64_t GetSfMin(int par, int ind) {
    return 1 <= ind && ind <= n ? sf_min[par][ind] : INT64_MAX;
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}