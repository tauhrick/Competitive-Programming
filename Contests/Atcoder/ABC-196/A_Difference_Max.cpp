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
  int a, b, c, d;  

  void Read() {
    cin >> a >> b >> c >> d; 
  }
 
  void Solve() {
    int max_diff = INT_MIN;
    for (int x = a; x <= b; ++x) {
      for (int y = c; y <= d; ++y) {
        max_diff = max(max_diff, x - y);
      }
    }
    cout << max_diff << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}