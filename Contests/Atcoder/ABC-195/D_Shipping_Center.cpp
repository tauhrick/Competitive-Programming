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
  int n, m, q;
  vector<int> w, v;
  vector<int> x;
  vector<pair<int, int>> queries;

  void Read() {
    cin >> n >> m >> q;
    w.resize(n);
    v.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> w[i] >> v[i];
    }
    x.resize(m);
    for (auto &i : x) {
      cin >> i;
    }
    queries.resize(q);
    for (auto &[l, r] : queries) {
      cin >> l >> r;
    }
  }
 
  void Solve() {
    for (auto &[l, r] : queries) {
      --l, --r;
      vector<int> valid_boxes;
      for (int i = 0; i < l; ++i) {
        valid_boxes.push_back(x[i]);
      }
      for (int i = r + 1; i < m; ++i) {
        valid_boxes.push_back(x[i]);
      }
      sort(valid_boxes.begin(), valid_boxes.end());
      vector<bool> taken(n);
      int res = 0;
      for (auto &b : valid_boxes) {
        int max_ind = -1;
        for (int i = 0; i < n; ++i) {
          if (!taken[i]) {
            if (w[i] <= b && (max_ind == -1 || v[i] > v[max_ind])) {
              max_ind = i;
            }
          }
        }
        if (max_ind != -1) {
          taken[max_ind] = true;
          res += v[max_ind];
        }
      }
      cout << res << '\n';
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}