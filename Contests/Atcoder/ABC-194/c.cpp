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

  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    int64_t ans = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      for (auto &p : cnt) {
        int64_t diff = abs(a[i] - p.first);
        ans += p.second * diff * diff;
      }
      ++cnt[a[i]];
    }
    cout << ans << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}