#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kInf = int(1.0e4);

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n, m; 
  vector<vector<int>> grid;

  void Read() {
    cin >> n >> m; 
    grid = vector(n, vector(m, 0));
    for (auto &row : grid) {
      for (auto &i : row) {
        cin >> i;
      }
    }
  }

  vector<vector<int>> up, down, left, right;
 
  void Solve() {
    up = vector(n, vector(m, 0));
    left = vector(n, vector(m, 0));
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        if (grid[r][c] == 0) continue;
        up[r][c] = 1 + (r - 1 >= 0 ? up[r - 1][c] : 0);
        left[r][c] = 1 + (c - 1 >= 0 ? left[r][c - 1] : 0);
      }
    }
    down = vector(n, vector(m, 0));
    right = vector(n, vector(m, 0));
    for (int r = n - 1; r >= 0; --r) {
      for (int c = m - 1; c >= 0; --c) {
        if (grid[r][c] == 0) continue;
        down[r][c] = 1 + (r + 1 < n ? down[r + 1][c] : 0);
        right[r][c] = 1 + (c + 1 < m ? right[r][c + 1] : 0);
      }
    }
    int64_t ans = 0;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        vector<int> neigh = {up[r][c], right[r][c], down[r][c], left[r][c]};
        for (int min_side = 0; min_side < 4; ++min_side) {
          int lc = max(0, min(neigh[min_side], neigh[(min_side + 3) % 4] / 2) - 1);
          int rc = max(0, min(neigh[min_side], neigh[(min_side + 1) % 4] / 2) - 1);
          ans += lc + rc;
        }
      }
    }
    cout << ans << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    cout << "Case #" << tt << ": ";
    Task t;
    t.Perform();
  }
  return 0;
}