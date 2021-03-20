#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kD = int(1.0e6);

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int64_t n;  

  void Read() {
    cin >> n; 
  }
 
  void Solve() {
    int res = 0;
    for (int i = 1; i <= kD; ++i) {
      int64_t x = stoll(to_string(i) + to_string(i));
      res += x <= n;
    }
    cout << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}