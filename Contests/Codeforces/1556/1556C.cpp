#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
 private:
  int n;
  vector<int> c;

  void Read() {
    cin >> n;
    c.resize(n);
    for (auto &i : c) {
      cin >> i;
    }
  }
 
  void Solve() {
    vector min_dip(n, vector(n, int64_t(0)));
    for (int l = 0; l < n; ++l) {
      int64_t ctr = 0;
      int64_t min_ctr = 0;
      for (int r = l + 1; r < n; ++r) {
        if (r % 2 == 1) {
          min_dip[l][r] = min_ctr;
          ctr -= c[r];
          min_ctr = min(min_ctr, ctr);
        } else {
          ctr += c[r];
        }
      }
    }
    vector max_jump(n, vector(n, int64_t(0)));
    for (int r = n - 1; r >= 0; --r) {
      int64_t ctr = 0;
      int64_t max_ctr = 0;
      for (int l = r - 1; l >= 0; --l) {
        if (l % 2 == 0) {
          max_jump[l][r] = max_ctr;
          ctr += c[l];
          max_ctr = max(max_ctr, ctr);
        } else {
          ctr -= c[l];
        }
      }
    }
    int64_t ans = 0;
    for (int l = 0; l < n; l += 2) {
      for (int r = l + 1; r < n; r += 2) {
        int64_t ded_l = -min_dip[l][r];
        int64_t ded_r = max_jump[l][r];
        if (c[l] < ded_l || c[r] < ded_r) {
          continue;
        }
        ans += min(c[l] - ded_l, c[r] - ded_r);
        if (ded_l > 0 && ded_r > 0) {
          ++ans;
        }
      }
    }
    cout << ans << '\n';
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Task t;
  t.Perform();
  return 0;
}
