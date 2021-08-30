#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
 private:
  int c, d; 

  void Read() {
    cin >> c >> d; 
  }
 
  void Solve() {
    int diff = abs(c - d);
    int ans = -1;
    if (diff == 0) {
      ans = (c == 0 ? 0 : 1);
    } else if (diff % 2 == 0) {
      ans = 2;
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
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}
