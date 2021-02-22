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
  vector<int> a;

  void Read() {
    cin >> n >> k;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    map<int, int> cnt_m;
    for (auto &i : a) {
      ++cnt_m[i % k];
    }
    int64_t best = 0;
    for (auto &i : cnt_m) {
      if (i.first == 0) continue;
      best = max(best, (k - i.first) + int64_t(i.second - 1) * k + 1);
    }
    cout << best << '\n';
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