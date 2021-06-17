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
    vector<array<int, 4>> moves;
    int r = 0, c = 0;
    while (true) {
      auto [nxt_r, nxt_c] = GetNext(r, c);
      if (nxt_r < n && nxt_c < m) {
        if (grid[r][c] % 2 == 1) {
          moves.push_back({r, c, nxt_r, nxt_c});
          ++grid[nxt_r][nxt_c];
          --grid[r][c];
        }
        r = nxt_r, c = nxt_c;
      } else {
        break;
      }
    }
    cout << moves.size() << '\n';
    for (auto &move : moves) {
      for (int i = 0; i < 4; ++i) {
        cout << move[i] + 1 << " \n"[i == 3];
      }
    }
  }

  pair<int, int> GetNext(int r, int c) {
    if (r % 2 == 0) {
      ++c;
      if (c == m) {
        c = m - 1;
        ++r;
      }
    } else {
      --c;
      if (c == -1) {
        c = 0;
        ++r;
      }
    }
    return make_pair(r, c);
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}