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
  vector<int64_t> x, y;

  void Read() {
    cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
      int xx, yy;
      cin >> xx >> yy;
      if (xx == 0) {
        y.push_back(1LL * yy * yy);
      } else {
        x.push_back(1LL * xx * xx);
      }
    }
  }
 
  void Solve() {
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    double res = 0; 
    for (int i = 0; i < n; ++i) {
      res += sqrt(x[i] + y[i]);
    }
    cout << fixed << setprecision(10) << res << '\n';
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