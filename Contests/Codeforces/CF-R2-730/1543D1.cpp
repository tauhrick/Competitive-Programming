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
  int n, k;  

  void Read() {
    cin >> n >> k; 
  }
 
  void Solve() {
    for (int i = 0; i < n; ++i) {
      int r = Ask(i == 0 ? i : i ^ (i - 1));
      if (r == 1) {
        return;
      }
    }
  }

  int Ask(int y) {
    cout << y << endl;
    int r;
    cin >> r;
    return r;
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