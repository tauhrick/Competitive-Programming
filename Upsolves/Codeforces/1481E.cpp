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
  vector<int> a;
  vector<vector<int>> inds;
  vector<int> dp;

  void Read() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
  }
 
  void Solve() {
    inds.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      inds[a[i]].push_back(i);
    }
    dp = vector(n + 1, -1);
    cout << Get(1) << '\n';
  }

  int Get(int ind) {
    if (ind >= n) {
      return 0;
    }
    auto &ans = dp[ind];
    if (ans == -1) {
      ans = 1 + Get(ind + 1);
      auto &locations = inds[a[ind]];
      if (ind == locations.front()) {
        int en = locations.back();
        int removes = (en - ind + 1) - int(locations.size());
        ans = min(ans, removes + Get(en + 1));
      }
      int pos = int(lower_bound(locations.begin(), locations.end(), ind) - locations.begin());
      int removes = (n - ind + 1) - (int(locations.size()) - pos);
      ans = min(ans, removes);
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