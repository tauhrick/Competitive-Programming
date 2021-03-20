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
  int n, k1, k2, w, b;

  void Read() {
    cin >> n >> k1 >> k2 >> w >> b;
  }
 
  void Solve() {
    if (k1 < k2) {
      swap(k1, k2);
    }
    w = max(0, w - k2 - (k1 - k2) / 2);
    b = max(0, b - (n - k1) - ((n - k2) - (n - k1)) / 2);
    cout << (max(w, b) == 0 ? "YES" : "NO") << '\n';
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