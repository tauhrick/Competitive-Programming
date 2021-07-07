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
  int64_t a, b; 

  void Read() {
    cin >> a >> b; 
  }
 
  void Solve() {
    if (a > b) {
      swap(a, b);
    }
    if (a == b) {
      cout << "0 0";
    } else {
      int64_t g = b - a;
      cout << b - a << ' ' << min(b % g, g - b % g);
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