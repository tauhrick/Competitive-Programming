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
  int n, x, m;
  vector<pair<int, int>> operations;

  void Read() {
    cin >> n >> x >> m;
    operations.resize(m);
    for (auto &op : operations) {
      cin >> op.first >> op.second;
    }
  }
 
  void Solve() {
    int left = x, right = x;
    for (auto &op : operations) {
      if (Intersect(left, right, op.first, op.second)) {
        left = min(left, op.first);
        right = max(right, op.second);
      }
    }
    cout << right - left + 1 << '\n';
  }

  bool Intersect(int l1, int r1, int l2, int r2) {
    return min(r1, r2) - max(l1, l2) + 1 > 0;
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