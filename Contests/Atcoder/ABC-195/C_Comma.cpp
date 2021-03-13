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
  int64_t n;

  void Read() {
    cin >> n;
  }
 
  void Solve() {
    int64_t ans = 0;
    int64_t st = 1;
    for (int c = 0; c < 10; ++c) {
      if (st > n) break;
      int64_t en = min(st * 1000 - 1, n);
      ans += (en - st + 1) * c;
      st = en + 1;
    }
    cout << ans << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}