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
  int n, k;  

  void Read() {
    cin >> n >> k; 
  }
 
  void Solve() {
    vector<int> ways(k);
    for (int i = 1; i <= n; ++i) {
      ++ways[i % k];
    }
    int64_t res = 0;
    for (int m = 0; m < k; ++m) {
      int o = (k - m) % k;
      if ((o + o) % k != 0) {
        continue;
      }
      if (m == o) {
        res += int64_t(ways[m]) * ways[m] * ways[m];
      } else {
        res += int64_t(ways[m]) * ways[o] * ways[o] * 3;
      }
    }
    cout << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}