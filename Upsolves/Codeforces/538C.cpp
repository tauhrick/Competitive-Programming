#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
 private:
  int n, m;  
  vector<int> d, h;

  void Read() {
    cin >> n >> m;
    d.resize(m);
    h.resize(m);
    for (int i = 0; i < m; ++i) {
      cin >> d[i] >> h[i];
    }
  }
 
  void Solve() {
    int max_height = max(h[0] + d[0] - 1, h[m - 1] + n - d[m - 1]);
    for (int i = 1; i < m; ++i) {
      int diff_h = abs(h[i] - h[i - 1]);
      int diff_d = d[i] - d[i - 1];
      if (diff_h > diff_d) {
        cout << "IMPOSSIBLE\n";
        return;
      }
      max_height = max(max_height, max(h[i - 1], h[i]) + (diff_d - diff_h) / 2);
    }
    cout << max_height << '\n';
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Task t;
  t.Perform();
  return 0;
}
