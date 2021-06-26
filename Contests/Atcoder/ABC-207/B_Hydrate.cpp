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
  int64_t a, b, c, d;  

  void Read() {
    cin >> a >> b >> c >> d; 
  }
 
  void Solve() {
    if (b >= c * d) {
      cout << -1;
    } else {
      int64_t den = c * d - b;
      cout << (a + den - 1) / den;
    }
    cout << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}