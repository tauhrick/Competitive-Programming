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
  vector<int> a, p, x;

  void Read() {
    cin >> n;
    a.resize(n);
    p.resize(n);
    x.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> p[i] >> x[i];
    }
  }
 
  void Solve() {
    int best_price = INT_MAX;
    for (int i = 0; i < n; ++i) {
      x[i] -= a[i];
      if (x[i] > 0) {
        best_price = min(best_price, p[i]);
      }
    }
    if (best_price == INT_MAX) {
      best_price = -1;
    }
    cout << best_price << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}