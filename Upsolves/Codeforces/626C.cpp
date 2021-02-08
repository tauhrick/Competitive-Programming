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
  int n, m;

  void Read() {
    cin >> n >> m;
  }
 
  void Solve() {
    for (int x = 0; ; ++x) {
      if (CanAllocate(x)) {
        cout << x << '\n';
        return;
      }
    }
  }

  bool CanAllocate(int x) {
    int mul_2 = x / 2;
    int mul_3 = x / 3;
    int mul_6 = x / 6;
    if (mul_2 < n || mul_3 < m) return false;
    int ded_2 = min(mul_6, mul_2 - n);
    mul_6 -= ded_2;
    int ded_3 = min(mul_6, mul_3 - m);
    mul_6 -= ded_3;
    return mul_6 == 0;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}