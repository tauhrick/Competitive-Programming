#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
 private:
  int n, m;  
  vector<string> grid;

  void Read() {
    cin >> n >> m;
    grid.resize(n);
    for (auto &row : grid) {
      cin >> row;
    }
  }
 
  void Solve() {
    int up = n, down = -1, left = m, right = -1;
    int black_cells = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 'B') {
          up = min(up, i);
          down = max(down, i);
          left = min(left, j);
          right = max(right, j);
          ++black_cells;
        }
      }
    }
    int ans = -1;
    if (black_cells == 0) {
      ans = 1;
    } else {
      int side = max(right - left + 1, down - up + 1);
      if (side <= min(n, m)) {
        ans = side * side - black_cells;
      }
    }
    cout << ans << '\n';
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Task t;
  t.Perform();
  return 0;
}
