#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "/Users/mac-mini/Desktop/CP/Library/Debug.hpp"
#endif

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }

 private:
  int n;
  vector<vector<int>> a;
  int x, y;

  void Read() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
      int l;
      cin >> l;
      a[i].resize(l);
      for (auto& j : a[i]) {
        cin >> j;
      }
    }
    cin >> x >> y;
  }

  void Solve() { cout << a[x - 1][y - 1] << '\n'; }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc = 1;
  // cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}
