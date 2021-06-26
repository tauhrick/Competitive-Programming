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
  int n; 
  vector<pair<int, int>> intervals;

  void Read() {
    cin >> n;
    intervals.resize(n);
    for (auto &[l, r] : intervals) {
      int typ;
      cin >> typ >> l >> r;
      l *= 2, r *= 2;
      if (typ == 2) {
        --r;
      } else if (typ == 3) {
        ++l;
      } else if (typ == 4) {
        ++l, --r;
      }
    } 
  }
 
  void Solve() {
    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int intersect = min(intervals[i].second, intervals[j].second) - max(intervals[i].first, intervals[j].first) + 1;
        res += intersect > 0;
      }
    }
    cout << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}