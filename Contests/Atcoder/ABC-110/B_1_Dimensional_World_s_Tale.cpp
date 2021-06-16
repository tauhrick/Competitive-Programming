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
  int n, m, cap_x, cap_y;  
  vector<int> x, y;

  void Read() {
    cin >> n >> m >> cap_x >> cap_y; 
    x.resize(n);
    for (auto &i : x) {
      cin >> i;
    }
    y.resize(m);
    for (auto &i : y) {
      cin >> i;
    }
  }
 
  void Solve() {
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    int l = max(x[n - 1], cap_x) + 1;
    int r = min(y[0], cap_y);
    cout << (l <= r ? "No War" : "War") << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}