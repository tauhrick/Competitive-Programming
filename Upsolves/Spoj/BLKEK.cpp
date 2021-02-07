#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kStates = 3;
const string kTar = "KEK";

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  string s;

  void Read() {
    cin >> s;
  }
 
  void Solve() {
    int n = int(s.size());
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(kStates + 1, 0));
    dp[n][kStates] = 1;
    for (int ind = n - 1; ind >= 0; --ind) {
      for (int state = kStates; state >= 0; --state) {
        dp[ind][state] = dp[ind + 1][state];
        if (state < kStates && s[ind] == kTar[state]) {
          dp[ind][state] += dp[ind + 1][state + 1];
        }
      }
    }
    cout << dp[0][0] << '\n';
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