#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int n, k;
  vector<int> h;
 
  void Read() {
    cin >> n >> k;
    h.resize(n);
    for (auto &i : h) {
      cin >> i;
    }
  }
 
  void Solve() {
    int lo = h[0], hi = h[0];
    bool good = true;
    for (int i = 1; i < n; ++i) {
      lo -= k - 1;
      hi += k - 1;
      lo = max(lo, h[i]);
      hi = min(hi, h[i] + (i == n - 1 ? 0 : k - 1));
      good &= lo <= hi;
    }
    cout << (good ? "YES" : "NO") << "\n";
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}