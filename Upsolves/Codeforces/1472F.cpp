#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  static const int kFull = 3;

  int n, m;
  map<int, int> blocks;
 
  void Read() {
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
      int r, c;
      cin >> r >> c;
      blocks[c] |= 1 << (r - 1);
    }
  }
 
  void Solve() {
    int prv = kFull;
    for (auto [x, mask] : blocks) {
      if (mask == kFull) {
        if (prv == kFull) {
          prv = kFull;
        } else {
          cout << "NO\n";
          return;
        }
      } else {
        int curr = (x + mask) & 1;
        if (prv == kFull) {
          prv = curr;
        } else if (prv == curr) {
          cout << "NO\n";
          return;
        } else {
          prv = kFull;
        }
      }
    }
    cout << (prv == kFull ? "YES" : "NO") << "\n";
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}