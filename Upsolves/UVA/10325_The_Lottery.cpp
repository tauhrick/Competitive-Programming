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
  vector<int> bad;

  void Read() {
    if (!(cin >> n >> m)) {
      exit(0);
    }
    bad.resize(m);
    for (int i = 0; i < m; ++i) {
      cin >> bad[i];
    }
  }
 
  void Solve() {
    int64_t res = n;
    for (int mask = 1; mask < (1 << m); ++mask) {
      bool no_change = false;
      int64_t div = 1;
      int cnt = 0;
      for (int i = 0; i < m; ++i) {
        if ((mask >> i) & 1) {
          ++cnt;
          div = (div * bad[i]) / __gcd(div, int64_t(bad[i]));
          if (div > n) {
            no_change = true;
            break;
          }
        }
      }
      if (!no_change) {
        if (cnt & 1) {
          res -= n / div;
        } else {
          res += n / div;
        }
      }
    }
    cout << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  while (true) {
    Task t;
    t.Perform();
  }
  return 0;
}