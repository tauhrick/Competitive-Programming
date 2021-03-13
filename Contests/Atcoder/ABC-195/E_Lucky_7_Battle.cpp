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
  string s, x;
  vector<int> pow_mod;
  vector<vector<int>> dp;

  void Read() {
    cin >> n >> s >> x;
  }
 
  void Solve() {
    pow_mod.resize(n);
    pow_mod[0] = 1;
    for (int i = 1; i < n; ++i) {
      pow_mod[i] = (pow_mod[i - 1] * 10) % 7;
    }
    dp = vector(n, vector(7, 0));
    cout << (Get(0, 0) == 1 ? "Takahashi" : "Aoki") << '\n';
  }

  int Get(int ind, int rem) {
    if (ind == n) {
      return rem == 0 ? 1 : -1;
    }
    auto &ans = dp[ind][rem];
    if (ans == 0) {
      int r_s = ((10 * rem) % 7 + (s[ind] - '0') % 7) % 7;
      int r_0 = (10 * rem) % 7;
      if (x[ind] == 'T') {
        ans = max(Get(ind + 1, r_s), Get(ind + 1, r_0));
      } else {
        ans = min(Get(ind + 1, r_s), Get(ind + 1, r_0));
      }
    }
    return ans;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}