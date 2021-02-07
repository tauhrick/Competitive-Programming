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
  int n, d, m;
  vector<int> a;

  void Read() {
    cin >> n >> d >> m;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    vector<int> less_vals = {0};
    vector<int> greater_vals;
    for (auto &i : a) {
      if (i <= m) {
        less_vals.push_back(i);
      } else {
        greater_vals.push_back(i);
      }
    }
    if (greater_vals.empty()) {
      cout << accumulate(a.begin(), a.end(), 0LL) << '\n';
      return;
    }
    sort(less_vals.rbegin(), less_vals.rend() - 1);
    sort(greater_vals.rbegin(), greater_vals.rend());
    vector<int64_t> pf_sum(less_vals.size());
    for (int i = 1; i < int(pf_sum.size()); ++i) {
      pf_sum[i] = pf_sum[i - 1] + less_vals[i];
    }
    int64_t ans = 0;
    int64_t greater_sum = 0;
    for (int take = 1; take <= int(greater_vals.size()); ++take) {
      greater_sum += greater_vals[take - 1];
      int64_t left_places = n - (take + 1LL * (take - 1) * d);
      if (left_places < 0)  {
        continue;
      }
      ans = max(ans, greater_sum + pf_sum[min(left_places, int64_t(pf_sum.size()) - 1)]);
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