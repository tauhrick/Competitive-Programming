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
  vector<vector<int>> grid;
  vector<int> big_cols;

  void Read() {
    cin >> n >> m;
    grid = vector(n, vector<int>(m));
    for (auto &row : grid) {
      for (auto &i : row) {
        cin >> i;
      }
    }
  }
 
  void Solve() {
    GetBigCols();
    cout << Brute(1) << '\n';
  }

  void GetBigCols() {
    auto col_taken = vector(m, false);
    vector<pair<int, int>> el_info;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        el_info.push_back({grid[i][j], j});
      }
    }
    sort(el_info.rbegin(), el_info.rend());
    for (int i = 0; i < int(el_info.size()) && int(big_cols.size()) < n; ++i) {
      if (!col_taken[el_info[i].second]) {
        col_taken[el_info[i].second] = true;
        big_cols.push_back(el_info[i].second);
      }
    }
  }

  int Brute(int ind) {
    int ans = INT_MIN;
    if (ind == int(big_cols.size())) {
      ans = 0;
      for (int r = 0; r < n; ++r) {
        int row_max = INT_MIN;
        for (auto &c : big_cols) {
          row_max = max(row_max, grid[r][c]);
        }
        ans += row_max;
      }
    } else {
      for (int d = 0; d < n; ++d) {
        vector<int> col;
        for (int r = 0; r < n; ++r) {
          col.push_back(grid[r][big_cols[ind]]);
        }
        rotate(col.begin(), col.begin() + d, col.end());
        CopyCol(col, big_cols[ind]);
        ans = max(ans, Brute(ind + 1));
        rotate(col.begin(), col.begin() + n - d, col.end());
        CopyCol(col, big_cols[ind]);
      }
    }
    return ans;
  }

  void CopyCol(vector<int> &col, int c) {
    for (int r = 0; r < n; ++r) {
      grid[r][c] = col[r];
    }
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