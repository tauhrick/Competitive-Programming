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
  vector<array<int, 2>> s;
  vector<array<int, 2>> t;

  void Read() {
    cin >> n;
    s.resize(n);
    for (auto &i : s) {
      cin >> i[0] >> i[1];
    }
    t.resize(n);
    for (auto &i : t) {
      cin >> i[0] >> i[1];
    }
  }
 
  void Solve() {
    vector<int> data_s = Arrange(s);
    vector<int> data_t = Arrange(t);
    if (data_s.size() == data_t.size()) {
      int sz = int(data_s.size()) / 3;
      if (sz == 0) {
        cout << "Yes\n";
        return;
      }
      for (int i = 0; i < sz; ++i) {
        if (data_s == data_t) {
          cout << "Yes\n";
          return;
        }
        rotate(data_s.begin(), data_s.begin() + 3, data_s.end());
      }
    }
    cout << "No\n";
  }

  vector<int> Arrange(vector<array<int, 2>> &v) {
    array<int, 2> sum_v = {0, 0};
    for (auto &i : v) {
      sum_v[0] += i[0];
      sum_v[1] += i[1];
      i[0] *= n;
      i[1] *= n;
    }
    for (auto &i : v) {
      i[0] -= sum_v[0];
      i[1] -= sum_v[1];
    }
    if (auto it = find(v.begin(), v.end(), array{0, 0}); it != v.end()) {
      v.erase(it);
    }
    sort(v.begin(), v.end(), [&](auto l, auto r) -> bool {
      double theta_l = atan2(l[1], l[0]);
      double theta_r = atan2(r[1], r[0]);
      if (theta_l != theta_r) {
        return theta_l < theta_r;
      } else {
        int mod_l = l[0] * l[0] + l[1] * l[1];
        int mod_r = r[0] * r[0] + r[1] * r[1];
        return mod_l < mod_r;
      }
    });
    vector<int> data;
    for (int i = 0, sz = int(v.size()); i < sz; ++i) {
      int x1 = v[i][0], y1 = v[i][1];
      int x2 = v[(i + 1) % sz][0], y2 = v[(i + 1) % sz][1];
      for (auto foo : {x1 * x1 + y1 * y1, x1 * x2 + y1 * y2, x1 * y2 - x2 * y1}) {
        data.push_back(foo);
      }
    }
    return data;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}