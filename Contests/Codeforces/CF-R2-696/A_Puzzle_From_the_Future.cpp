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
  string b;

  void Read() {
    cin >> n >> b;
  }
 
  void Solve() {
    int prv = -1;
    for (int i = 0; i < n; ++i) {
      int bit = int(b[i] - '0');
      for (auto add : {1, 0}) {
        if (add + bit != prv) {
          prv = add + bit;
          cout << add;
          break;
        }
      }
    }
    cout << "\n";
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}