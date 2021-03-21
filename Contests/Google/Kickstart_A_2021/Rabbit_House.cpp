#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kInf = int(2.0e9);
const vector dr = {0, 0, -1, 1};
const vector dc = {-1, 1, 0, 0};

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
 
  void Solve() {
    int mx_val = -kInf;
    for (auto &row : grid) {
      for (auto &i : row) {
        mx_val = max(mx_val, i);
      }
    }
    auto inds = vector(mx_val + 1, vector<pair<int, int>>{});
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        inds[grid[r][c]].push_back({r, c});
      }
    }
    auto seen = vector(n, vector(m, false));
    auto col = vector(n, vector(m, -1));
    queue<pair<int, int>> q;
    int dep = mx_val;
    while (dep > 0) {
      for (auto &p : inds[dep]) {
        if (seen[p.first][p.second]) continue;
        q.push(p);
        seen[p.first][p.second] = true;
        col[p.first][p.second] = dep;
      }
      int sz = int(q.size());
      if (sz == 0) break;
      while (sz--) {
        auto [r, c] = q.front();
        q.pop();
        for (int d = 0; d < 4; ++d) {
          int n_r = r + dr[d];
          int n_c = c + dc[d];
          if (0 <= n_r && n_r < n && 0 <= n_c && n_c < m && !seen[n_r][n_c]) {
            q.push({n_r, n_c});
            seen[n_r][n_c] = true;
            col[n_r][n_c] = dep - 1;
          }
        }
      }
      --dep;
    }
    int64_t res = 0;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < m; ++c) {
        assert(col[r][c] >= grid[r][c]);
        res += col[r][c] - grid[r][c];
      }
    }
    cout << res << '\n';
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