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
  int r, b, d; 

  void Read() {
    cin >> r >> b >> d; 
  }
 
  void Solve() {
    if (r > b) {
      swap(r, b);
    }
    cout << ((b + r - 1) / r - 1 <= d ? "YES" : "NO") << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}