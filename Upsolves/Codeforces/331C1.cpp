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

  void Read() {
    cin >> n;
  }
 
  void Solve() {
    vector<int> dp(n + 1);
    for (int x = 1; x <= n; ++x) {
      dp[x] = INT_MAX;
      for (auto dig : to_string(x)) {
        if (dig == '0') continue;
        dp[x] = min(dp[x], dp[x - int(dig - '0')] + 1);
      }
    }
    cout << dp[n] << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}