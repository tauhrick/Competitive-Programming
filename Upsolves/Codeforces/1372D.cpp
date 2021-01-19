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

  void Read() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    } 
  }
 
  void Solve() {
    vector<int64_t> pf(n + 1);
    for (int i = 1; i <= n; ++i) {
      pf[i] = (i - 2 >= 0 ? pf[i - 2] : 0) + a[i];
    }
    vector<int64_t> sf(n + 2);
    for (int i = n; i >= 1; --i) {
      sf[i] = (i + 2 <= n ? sf[i + 2] : 0) + a[i];
    }
    int64_t best = pf[n];
    for (int i = 1; i + 1 <= n; ++i) {
      best = max(best, pf[i] + sf[i + 1]);
    }
    cout << best << "\n";
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Task t;
  t.Perform();
  return 0;
}