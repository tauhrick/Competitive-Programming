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
  int a, b, c;  

  void Read() {
    cin >> a >> b >> c;
  }
 
  void Solve() {
    vector digits = {a, b, c};
    sort(digits.begin(), digits.end());
    cout << 10 * digits[2] + digits[0] + digits[1] << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}