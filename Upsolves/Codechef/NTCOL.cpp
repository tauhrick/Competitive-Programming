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
  array<pair<int, char>, 3> cnt;
  vector<string> grid;

  void Read() {
    cin >> n >> m;
    for (auto &c : cnt) {
      cin >> c.first;
    }
  }
 
  void Solve() {
    string colors = "RGB";
    for (int i = 0; i < 3; ++i) {
      cnt[i].second = colors[i];
    }
    sort(cnt.begin(), cnt.end());
    swap(cnt[1], cnt[2]);
    grid = vector(n, string(m, '#'));
    for (int parity = 0, ctr = 0; parity <= 1; ++parity) {
      for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
          if ((r + c) % 2 == parity && grid[r][c] == '#') {
            while (cnt[ctr].first == 0) {
              ++ctr;
            }
            grid[r][c] = cnt[ctr].second;
            --cnt[ctr].first;
          }
        }
      }
    }
    for (auto &row : grid) {
      cout << row << "\n";
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