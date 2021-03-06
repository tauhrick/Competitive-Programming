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
  int n, k;

  void Read() {
    cin >> n >> k;
  }
 
  void Solve() {
    vector<int> res;
    for (int i = (k - 1) / 2 + 1; i <= n; ++i) {
      if (i != k) {
        res.push_back(i);
      }
    }
    cout << res.size() << '\n';
    for (auto &i : res) {
      cout << i << ' ';
    }
    cout << '\n';
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