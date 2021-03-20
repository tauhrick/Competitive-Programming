#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int64_t kInf = int64_t(1.0e17);

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n, q;
  vector<int> a, t;
  vector<int64_t> x;

  void Read() {
    cin >> n;
    a.resize(n);
    t.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> t[i];
    }
    cin >> q;
    x.resize(q);
    for (auto &i : x) {
      cin >> i;
    }
  }
 
  void Solve() {
    pair<int64_t, int64_t> possible_range = {-kInf, kInf};
    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
      if (t[i] == 1) {
        sum += a[i];
      } else if (t[i] == 2) {
        possible_range.first = max(possible_range.first, a[i] - sum);
        possible_range.second = max(possible_range.second, a[i] - sum);
      } else {
        possible_range.first = min(possible_range.first, a[i] - sum);
        possible_range.second = min(possible_range.second, a[i] - sum);
      }
    }
    for (auto qry : x) {
      qry = max(qry, possible_range.first);
      qry = min(qry, possible_range.second);
      cout << qry + sum << '\n';
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}