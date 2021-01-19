#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
 private:
  array<int, 3> n;
  array<vector<int>, 3> a;

  void Read() {
    for (auto &i : n) {
      cin >> i;
    }
    for (int i = 0; i < 3; ++i) {
      a[i].resize(n[i]);
      for (auto &j : a[i]) {
        cin >> j;
      }
    }
  }
 
  void Solve() {
    for (auto &bag : a) {
      sort(bag.begin(), bag.end());
    }
    vector<int> order = {0, 1, 2};
    int64_t best = INT64_MIN;
    for (int final = 0; final < 3; ++final) {
      best = max(best, Get(order));
      rotate(order.begin(), order.begin() + 1, order.end());
    }
    cout << best << "\n";
  }

  int64_t Get(vector<int> &order) {
    int64_t ans = accumulate(a[order[0]].begin(), a[order[0]].end(), int64_t(0));
    int m1 = a[order[1]][0];
    int m2 = a[order[2]][0];
    int64_t s1 = accumulate(a[order[1]].begin(), a[order[1]].end(), int64_t(0)) - m1;
    int64_t s2 = accumulate(a[order[2]].begin(), a[order[2]].end(), int64_t(0)) - m2;
    return ans + max({s1 - m1 + s2 - m2, s2 + m2 - s1 - m1, s1 + m1 - m2 - s2});
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