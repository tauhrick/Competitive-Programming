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
  int a, b, w;

  void Read() {
    cin >> a >> b >> w;
  }
 
  void Solve() {
    int mn = INT_MAX, mx = INT_MIN;
    w *= 1000;
    for (int o = 1; o <= w; ++o) {
      if (a * o <= w && w <= b * o) {
        mn = min(mn, o);
        mx = max(mx, o);
      }
    }
    if (mn == INT_MAX) {
      cout << "UNSATISFIABLE";
    } else {
      cout << mn << ' ' << mx;
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