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
  vector<pair<int, int>> ab;

  void Read() {
    cin >> n;
    ab.resize(n);
    for (auto &i : ab) {
      cin >> i.first >> i.second;
    }
  }
 
  void Solve() {
    int res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) {
          res = min(res, ab[i].first + ab[i].second);
        } else {
          res = min(res, max(ab[i].first, ab[j].second));
        }
      }
    }
    cout << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}