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
    priority_queue<pair<int64_t, int>> split_size;
    vector<int> splits(n, 1);
    for (int i = 0; i < n; ++i) {
      split_size.push({Cost(i, 1) - Cost(i, 2), i});
    }
    int rem_splits = k - n;
    while (rem_splits--) {
      auto [_, ind] = split_size.top();
      split_size.pop();
      ++splits[ind];
      split_size.push({Cost(ind, splits[ind]) - Cost(ind, splits[ind] + 1), ind});
    }
    int64_t res = 0;
    for (int i = 0; i < n; ++i) {
      res += Cost(i, splits[i]);
    }
    cout << res << '\n';
  }

  int64_t Cost(int ind, int parts) {
    int nc = a[ind] % parts;
    int c = parts - nc;
    int s = a[ind] / parts;
    return int64_t(c) * s * s + int64_t(nc) * (s + 1) * (s + 1);
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}