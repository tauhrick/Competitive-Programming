/*
  https://www.codechef.com/problems/SPIT2

  - Use bitmask dp
  - dp[ind][ones] = dp[ind - 1][0] + (ones < m ? dp[ind - 1][ones + 1] : 0)
  - dp[0][0..m] = 1, dp[0][m + 1..] = 0
*/

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

  void Read() {
    cin >> m >> n;
  }
 
  void Solve() {
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m, 0));
    fill(dp[0].begin(), dp[0].end(), 1);
    for (int ind = 1; ind <= n; ++ind) {
      for (int ones = 0; ones < m; ++ones) {
        dp[ind][ones] = dp[ind - 1][0];
        if (ones < m - 1) {
          dp[ind][ones] += dp[ind - 1][ones + 1];
        }
      }
    }
    cout << dp[n][0] << "\n";
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