#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kInf = int(1e7);

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n, k;
  vector<int> prices;
  vector<vector<vector<int>>> dp;
  vector<vector<vector<int>>> seen;

  void Read() {
    cin >> n >> k;
    prices.resize(k + 1);
    for (int i = 1; i <= k; ++i) {
      cin >> prices[i];
    }
  }
 
  void Solve() {
    dp.assign(k + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, 0)));
    seen.assign(k + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, false)));
    int ans = Get(1, k, n);
    cout << (ans == kInf ? -1 : ans) << '\n';
  }

  int Get(int ind, int rem_weight, int rem_packets) {
    if (ind == k + 1) {
      return rem_weight == 0 ? 0 : kInf;
    }
    auto &ans = dp[ind][rem_weight][rem_packets];
    auto &vis = seen[ind][rem_weight][rem_packets];
    if (!vis) {
      vis = true;
      ans = Get(ind + 1, rem_weight, rem_packets);
      if (prices[ind] != -1 && rem_weight - ind >= 0 && rem_packets - 1 >= 0) {
        int nxt = Get(ind, rem_weight - ind, rem_packets - 1);
        if (nxt != kInf) {
          ans = min(ans, prices[ind] + nxt);
        }
      }
    }
    return ans;
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