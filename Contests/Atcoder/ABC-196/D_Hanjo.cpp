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
  int h, w, a, b;  
  vector<tuple<int, int, int, int>> moves;
  vector<vector<vector<int64_t>>> dp;

  void Read() {
    cin >> h >> w >> a >> b; 
  }
 
  void Solve() {
    for (int r = 0; r < w; ++r) {
      for (int c = 1; c < h; ++c) {
        moves.push_back({r, c - 1, r, c});
      }
    }
    for (int c = 0; c < h; ++c) {
      for (int r = 1; r < w; ++r) {
        moves.push_back({r - 1, c, r, c});
      }
    }
    dp = vector(moves.size(), vector(1 << (h * w), vector(a + 1, int64_t(-1))));
    cout << Get(0, 0, 0) << '\n';
  }

  int64_t Get(int ind, int mask, int double_placed) {
    if (double_placed > a) {
      return 0;
    } else if (ind == int(moves.size())) {
      return double_placed == a;
    }
    auto &ans = dp[ind][mask][double_placed];
    if (ans == -1) {
      ans = Get(ind + 1, mask, double_placed);
      auto [r1, c1, r2, c2] = moves[ind];
      if (!Taken(mask, Position(r1, c1)) && !Taken(mask, Position(r2, c2))) {
        ans += Get(ind + 1, mask | (1 << Position(r1, c1)) | (1 << Position(r2, c2)), double_placed + 1);
      }
    }
    return ans;
  }

  bool Taken(int mask, int bit) {
    return (mask >> bit) & 1;
  }

  int Position(int r, int c) {
    return r * h + c;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}