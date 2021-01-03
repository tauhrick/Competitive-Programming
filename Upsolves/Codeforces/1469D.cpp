#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int n;
 
  void Read() {
    cin >> n;
  }
 
  void Solve() {
    vector<pair<int, int>> ops;
    while (n != 2) {
      int x = int(sqrt(n));
      if (x * x != n) {
        ++x;
      }
      for (int i = n - 1; i > x; --i) {
        ops.emplace_back(i, n);
      }
      ops.emplace_back(n, x);
      ops.emplace_back(n, x);
      n = x;
    }
    cout << ops.size() << '\n';
    for (auto &[x, y] : ops) {
      cout << x << ' ' << y << '\n';
    }
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}