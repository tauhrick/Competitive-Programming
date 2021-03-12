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
  vector<int> p;

  void Read() {
    cin >> n;
    p.resize(n + 2);
    for (int i = 1; i <= n; ++i) {
      cin >> p[i];
    }
  }
 
  void Solve() {
    vector<pair<int, int>> left_info(n + 2);
    vector<int> pf(n + 2);
    for (int i = 1; i <= n; ++i) {
      left_info[i].first = 1 + (i - 1 > 0 && p[i - 1] < p[i] ? left_info[i - 1].first : 0);
      left_info[i].second = 1 + (i - 1 > 0 && p[i - 1] > p[i] ? left_info[i - 1].second : 0);
      pf[i] = max({pf[i - 1], left_info[i].first, left_info[i].second});
    }
    vector<pair<int, int>> right_info(n + 2);
    vector<int> sf(n + 2);
    for (int i = n; i > 0; --i) {
      right_info[i].first = 1 + (i + 1 <= n && p[i + 1] < p[i] ? right_info[i + 1].first : 0);
      right_info[i].second = 1 + (i + 1 <= n && p[i + 1] > p[i] ? right_info[i + 1].second : 0);
      sf[i] = max({sf[i + 1], right_info[i].first, right_info[i].second});
    }
    int good = 0;
    for (int i = 1; i <= n; ++i) {
      int min_side = min(left_info[i].first, right_info[i].first);
      int max_side = max(left_info[i].first, right_info[i].first);
      int max_inc = max(pf[i - left_info[i].first + 1], sf[i + right_info[i].first - 1]);
      if (min_side == 1 || max_inc >= max_side) continue;
      max_side -= max_side % 2 == 1;
      if (min_side > max_side) {
        ++good;
      }
    }
    cout << good << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}