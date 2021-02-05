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
  int px, py;
  string s;

  void Read() {
    cin >> px >> py;
    cin >> s;
  }
 
  void Solve() {
    int cx = 0, cy = 0;
    for (auto &ch : s) {
      auto [dx, dy] = GetMove(ch);
      int nx = cx + dx;
      int ny = cy + dy;
      if (Dist(nx, ny) < Dist(cx, cy)) {
        cx = nx;
        cy = ny;
      }
    }
    cout << (make_pair(cx, cy) == make_pair(px, py) ? "YES" : "NO") << '\n';
  }

  pair<int, int> GetMove(char ch) {
    if (ch == 'U') {
      return {0, 1};
    } else if (ch == 'D') {
      return {0, -1};
    } else if (ch == 'L') {
      return {-1, 0};
    } else {
      return {1, 0};
    }
  }

  int Dist(int x, int y) {
    return abs(x - px) + abs(y - py);
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