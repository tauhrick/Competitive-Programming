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
  int n, m; 
  vector<vector<int64_t>> grid;

  void Read() {
    cin >> n >> m; 
    grid = vector(n, vector(m, int64_t(0)));
    for (auto &row : grid) {
      for (auto &i : row) {
        cin >> i;
      }
    }
  }
 
  void Solve() {
    int64_t ans = INT64_MAX;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        vector pf = vector(n, vector(m, INT64_MAX));
        for (int r = i; r >= 0; --r) {
          for (int c = j; c >= 0; --c) {
            int dist = i - r + j - c;
            if (grid[r][c] >= grid[i][j] - dist) {
              if (r + 1 <= i) {
                pf[r][c] = min(pf[r][c], pf[r + 1][c]);
              }
              if (c + 1 <= j) {
                pf[r][c] = min(pf[r][c], pf[r][c + 1]);
              }
              if (pf[r][c] == INT64_MAX) {
                if (r == i && c == j) {
                  pf[r][c] = grid[r][c] - (grid[i][j] - dist);
                }
              } else {
                pf[r][c] += grid[r][c] - (grid[i][j] - dist);
              }
            }
          }
        }
        vector sf = vector(n, vector(m, INT64_MAX));
        for (int r = i; r < n; ++r) {
          for (int c = j; c < m; ++c) {
            int dist = -(i - r + j - c);
            if (grid[r][c] >= grid[i][j] + dist) {
              if (r - 1 >= i) {
                sf[r][c] = min(sf[r][c], sf[r - 1][c]);
              }
              if (c - 1 >= j) {
                sf[r][c] = min(sf[r][c], sf[r][c - 1]);
              }
              if (sf[r][c] == INT64_MAX) {
                if (r == i && c == j) {
                  sf[r][c] = grid[r][c] - (grid[i][j] + dist);
                }
              } else {
                sf[r][c] += grid[r][c] - (grid[i][j] + dist);
              }
            }
          }
        }
        if (pf[0][0] != INT64_MAX && sf[n - 1][m - 1] != INT64_MAX) {
          ans = min(ans, pf[0][0] + sf[n - 1][m - 1]);
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
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}