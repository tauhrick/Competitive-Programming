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
 
  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    vector<int64_t> dp(n);
    for (int i = n - 1; i >= 0; --i) {
      int64_t nxt = i + a[i] < n ? dp[i + a[i]] : 0;
      dp[i] = a[i] + nxt;
    }
    cout << *max_element(dp.begin(), dp.end()) << "\n";
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