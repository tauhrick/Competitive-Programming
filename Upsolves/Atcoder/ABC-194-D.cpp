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
  int n;

  void Read() {
    cin >> n; 
  }
 
  void Solve() {
    double res = 0;
    for (int i = n - 1; i >= 1; --i) {
      res += n / double(i);
    }
    cout << fixed << setprecision(10) << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}