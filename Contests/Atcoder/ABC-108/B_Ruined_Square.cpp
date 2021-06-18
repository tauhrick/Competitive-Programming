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
  int x1, y1, x2, y2;  

  void Read() {
    cin >> x1 >> y1 >> x2 >> y2; 
  }
 
  void Solve() {
    int dx = x2 - x1, dy = y2 - y1;
    int x3 = x2 - dy, y3 = y2 + dx;
    int x4 = x1 - dy, y4 = y1 + dx;
    cout << x3 << ' ' << y3 << ' ' << x4 << ' ' << y4 << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}