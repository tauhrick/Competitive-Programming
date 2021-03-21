#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kInf = int(2.0e9);

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n;
  vector<vector<int>> a, b;
  vector<int> row_xor, col_xor;

  void Read() {
    cin >> n;
    a = vector(n, vector(n, 0));
    for (auto &row : a) {
      for (auto &i : row) {
        cin >> i;
      }
    }
    b = vector(n, vector(n, 0));
    for (auto &row : b) {
      for (auto &i : row) {
        cin >> i;
      }
    }
    row_xor.resize(n);
    for (auto &i : row_xor) {
      cin >> i;
    }
    col_xor.resize(n);
    for (auto &i : col_xor) {
      cin >> i;
    }
  }

  vector<pair<int, int>> moves;
  vector<vector<int64_t>> dp;
  int64_t sum;
  int mask_full;
 
  void Solve() {
    sum = 0;
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (b[r][c] != 0) {
          moves.push_back({r, c});
          sum += b[r][c];
        }
      }
    }
    mask_full = (1 << n);
    dp = vector(1 << n, vector(1 << n, int64_t(-1)));
    cout << Get(0, 0) << '\n';
  }

  int64_t Get(int mask_row, int mask_col) {
    if (mask_row == mask_full || mask_col == mask_full) {
      return sum;
    }
    auto &ans = dp[mask_row][mask_col];
    if (ans == -1) {
      ans = sum;
      for (int i = 0; i < int(moves.size()); ++i) {
        bool done_row = (mask_row >> moves[i].first) % 2 == 1;
        bool done_col = (mask_col >> moves[i].second) % 2 == 1;
        if (done_row && done_col) continue;
        ans = min(ans, -b[moves[i].first][moves[i].second] + Get(mask_row | (1 << moves[i].first), mask_col | (1 << moves[i].second)));
      }
    }
    return ans;
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