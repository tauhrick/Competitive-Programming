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
  int t, n;  

  void Read() {
    cin >> t >> n; 
  }
 
  void Solve() {
    int64_t lo = 1, hi = int64_t(1.0e15);
    while (lo < hi) {
      int64_t mid = lo + ((hi - lo) >> 1);
      if (GetTaxPrice(mid) - mid >= n) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    cout << GetTaxPrice(lo) - 1 << '\n';
  }

  int64_t GetTaxPrice(int64_t x) {
    return ((100 + t) * x) / 100;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}