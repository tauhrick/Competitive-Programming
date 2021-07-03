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
  int n, a, b; 

  void Read() {
    cin >> n >> a >> b; 
  }
 
  void Solve() {
    if (a == 1) {
      cout << ((n - 1) % b == 0 ? "Yes" : "No") << '\n';
      return;
    }
    int64_t pow_a = 1;
    while (pow_a <= n) {
      if ((n - pow_a) % b == 0) {
        cout << "Yes\n";
        return;
      }
      pow_a *= a;
    }
    cout << "No\n";
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