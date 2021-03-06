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
  int n, m, w;
  vector<int> a;

  void Read() {
    cin >> n >> m >> w;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    int lo = 0, hi = int(2e9);
    while (lo < hi) {
      int mid = lo + ((hi - lo + 1) >> 1);
      if (Can(mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    cout << lo << '\n';
  }

  bool Can(int height) {
    vector<int> dec_op(n + w);
    int64_t req_moves = 0;
    for (int i = 0, extra = 0; i < n; ++i) {
      extra -= dec_op[i];
      int req_now = max(0, height - (a[i] + extra));
      req_moves += req_now;
      extra += req_now;
      dec_op[i + w] = req_now;
    }
    return req_moves <= m;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}