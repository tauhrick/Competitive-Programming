#include <atcoder/math>

#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int64_t kInf = INT64_MAX;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int64_t x, y, p, q;

  void Read() {
    cin >> x >> y >> p >> q;
  }
 
  void Solve() {
    int64_t d1 = p + q;
    int64_t d2 = 2 * (x + y);
    int64_t best = kInf;
    for (int64_t r1 = p; r1 < p + q; ++r1) {
      for (int64_t r2 = x; r2 < x + y; ++r2) {
        auto [yy, zz] = atcoder::crt({r1, r2}, {d1, d2});
        if (zz == 0) continue;
        best = min(best, int64_t(yy));
      }
    }
    if (best == kInf) {
      cout << "infinity\n";
    } else {
      cout << best << '\n';
    }
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
