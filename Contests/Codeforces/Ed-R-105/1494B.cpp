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
  vector<int> sides;

  void Read() {
    cin >> n;
    sides.resize(4);
    for (auto &side : sides) {
      cin >> side;
    }
  }
 
  void Solve() {
    vector corners = {0, 1, 2, 3};
    do {
      auto sides_copy = sides;
      for (auto &corner : corners) {
        int a = corner;
        int b = (corner + 3) % 4;
        if (sides_copy[a] > 0 && sides_copy[b] > 0) {
          --sides_copy[a];
          --sides_copy[b];
        }
      }
      bool ok = true;
      for (auto &side : sides_copy) {
        ok &= side <= n - 2;
      }
      if (ok) {
        cout << "YES\n";
        return;
      }
    } while (next_permutation(corners.begin(), corners.end()));
    cout << "NO\n";
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