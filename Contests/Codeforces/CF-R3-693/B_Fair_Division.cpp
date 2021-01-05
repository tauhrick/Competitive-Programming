#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int n;
  vector<int> a;
  vector<vector<int>> dp, seen;
  int tar;
 
  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    tar = accumulate(a.begin(), a.end(), 0);
    if (tar & 1) {
      cout << "NO\n";
      return;
    }
    tar /= 2;
    dp = vector(n, vector(2 * n + 1, 0));
    seen = vector(n, vector(2 * n + 1, 0));
    cout << (Get(0, 0) ? "YES" : "NO") << "\n";
  }

  bool Get(int ind, int taken) {
    if (ind == n) {
      return taken == tar;
    }
    auto &ans = dp[ind][taken];
    auto &vis = seen[ind][taken];
    if (!vis) {
      vis = true;
      ans = Get(ind + 1, taken) || Get(ind + 1, taken + a[ind]);
    }
    return ans;
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}