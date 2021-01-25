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
  int m, n;
  vector<int> a, b;
  vector<vector<int64_t>> dp;

  void Read() {
    cin >> m >> n;
    if (make_pair(m, n) == make_pair(0, 0)) {
      exit(0);
    }
    a.resize(m);
    b.resize(m);
    for (int i = 0; i < m; ++i) {
      cin >> a[i] >> b[i];
    }
  }
 
  void Solve() {
    dp.assign(m, vector<int64_t>(n + 1, -1));
    cout << Get(0, n) << "\n";
  }

  int64_t Get(int ind, int left) {
    if (ind == m) {
      return left == 0;
    }
    auto &ans = dp[ind][left];
    if (ans == -1) {
      ans = 0;
      for (int take = a[ind]; left - take >= 0 && take <= b[ind]; ++take) {
        ans += Get(ind + 1, left - take);
      }
    }
    return ans;
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  while (true) {
    Task t;
    t.Perform();
  }
  return 0;
}