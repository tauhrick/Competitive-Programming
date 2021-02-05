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
  vector<int> d;
  vector<int> a;

  void Read() {
    cin >> n >> m;
    d.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> d[i];
    }
    a.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
      cin >> a[i];
    }
  }
 
  void Solve() {
    int lo = 1, hi = n;
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (Can(mid)) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    cout << (Can(lo) ? lo : -1) << '\n';
  }

  bool Can(int x) {
    auto seen = vector(m + 1, false);
    auto done = vector(m + 1, false);
    auto rem = a;
    queue<int> place;
    for (int i = x; i >= 1; --i) {
      if (!seen[d[i]] && d[i] != 0) {
        place.push(d[i]);
        seen[d[i]] = true;
      } else {
        if (place.empty()) continue;
        int col = place.front();
        --rem[col];
        if (rem[col] == 0) {
          place.pop();
          done[col] = true;
        }
      }
    }
    return accumulate(done.begin() + 1, done.end(), 0) == m;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}