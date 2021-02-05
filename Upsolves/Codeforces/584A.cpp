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
  int n, t;

  void Read() {
    cin >> n >> t;
  }
 
  void Solve() {
    if (t == 10 && n == 1) {
      cout << -1 << '\n';
      return;
    }
    string res(n, char('0' + t % 10));
    if (t == 10) {
      res[0] = '1';
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