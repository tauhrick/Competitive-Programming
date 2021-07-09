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

  void Read() {
    cin >> n >> m;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    int64_t lo = 1, hi = int64_t(1.0e18);
    while (lo < hi) {
      int64_t mid = lo + ((hi - lo) >> 1);
      if (CanFinish(mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    cout << lo << '\n';
  }

  bool CanFinish(int64_t t) {
    vector cpy_a = a;
    int ctr = 0;
    for (int s = 1; s <= m && ctr < n; ++s) {
      int64_t rem = t - (ctr + 1);
      while (rem > 0 && ctr < n) {
        int64_t ded = min(rem, int64_t(cpy_a[ctr]));
        cpy_a[ctr] -= int(ded);
        rem -= ded;
        if (cpy_a[ctr] == 0) {
          ++ctr;
          --rem;
        }
      }
    }
    while (ctr < n && cpy_a[ctr] == 0) {
      ++ctr;
    }
    return ctr == n;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}