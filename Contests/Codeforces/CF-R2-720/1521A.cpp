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
  int a, b; 

  void Read() {
    cin >> a >> b;
  }
 
  void Solve() {
    if (b == 1) {
      cout << "NO";
    } else {
      cout << "YES\n";
      int64_t x = a;
      int64_t y = int64_t(a) * b;
      int64_t z = x + y;
      cout << x << ' ' << y << ' ' << z;
    }
    cout << '\n';
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