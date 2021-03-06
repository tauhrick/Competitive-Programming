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
    a += b;
    if (a >= 15 && b >= 8) {
      cout << 1;
    } else if (a >= 10 && b >= 3) {
      cout << 2;
    } else if (a >= 3) {
      cout << 3;
    } else {
      cout << 4;
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