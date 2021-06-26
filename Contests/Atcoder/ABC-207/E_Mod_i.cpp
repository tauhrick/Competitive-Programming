#include <atcoder/modint>

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
  using Mint = atcoder::modint1000000007;

  int n;
  vector<int64_t> a; 
  vector<int64_t> pf;
  vector<vector<int>> nxt;
  vector<vector<Mint>> dp;
  vector<vector<int>> seen;

  void Read() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
  }
 
  void Solve() {
    pf = a;
    for (int i = 1; i <= n; ++i) {
      pf[i] += pf[i - 1];
    }
    nxt = vector(n + 1, vector(n + 1, -1));
    for (int mod = 1; mod <= n; ++mod) {
      vector<int> nxt_loc(mod, -1);
      for (int i = n; i >= 0; --i) {
        nxt[mod][i] = nxt_loc[pf[i] % mod];
        nxt_loc[pf[i] % mod] = i;
      }
    }
    dp = vector(n + 1, vector(n + 1, Mint(0)));
    seen = vector(n + 1, vector(n + 1, 0));
    cout << Get(0, 1).val() << '\n';
  }

  Mint Get(int ind, int set_no) {
    if (ind == n) {
      return Mint(1);
    }
    auto &ans = dp[ind][set_no];
    auto &vis = seen[ind][set_no];
    if (!vis) {
      vis = true;
      auto Update = [&](int s) -> void {
        int nxt_ind = nxt[s][ind];
        if (nxt_ind != -1) {
          ans += Get(nxt_ind, s);
        }
      };
      Update(set_no);
      if (ind != 0) {
        Update(set_no + 1);
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