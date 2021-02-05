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
  vector<int> h;
  int prv;

  void Read() {
    cin >> n >> k;
    h.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> h[i];
    }
  }
 
  void Solve() {
    for (int i = 1; i <= k; ++i) {
      if (!Simulate()) {
        cout << -1 << '\n'; 
        return;
      }
    }
    cout << prv << '\n';
  }

  bool Simulate() {
    for (int i = 1; i < n; ++i) {
      if (h[i] < h[i + 1]) {
        ++h[i];
        prv = i;
        return true;
      }
    }
    return false;
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