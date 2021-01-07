#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

const int kMod = int(1e9) + 7;

class Task {
 private:
  int n;
  vector<string> grid;

  void Read() {
    cin >> n;
    grid.resize(n);
    for (auto &row : grid) {
      cin >> row;
    }
  }
 
  void Solve() {
    auto paths = vector(n, vector(n, 0));
    paths[0][0] = (grid[0][0] == '.');
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        if (grid[r][c] == '*') continue;
        if (r - 1 >= 0) {
          paths[r][c] += paths[r - 1][c];
          paths[r][c] %= kMod;
        }
        if (c - 1 >= 0) {
          paths[r][c] += paths[r][c - 1];
          paths[r][c] %= kMod;
        }
      }
    }
    cout << paths[n - 1][n - 1] << "\n";
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