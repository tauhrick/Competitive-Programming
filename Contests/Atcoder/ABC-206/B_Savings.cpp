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
    for (int i = 1; ; ++i) {
      if ((1LL * i * (i + 1)) / 2 >= n) {
        cout << i << '\n';
        return;
      }
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}