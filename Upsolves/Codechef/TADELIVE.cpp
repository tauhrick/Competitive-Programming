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
  int n, x, y;
  vector<int> a;
  vector<int> b;

  void Read() {
    cin >> n >> x >> y;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
    b.resize(n);
    for (auto &i : b) {
      cin >> i;
    }
  }
 
  void Solve() {
    int tot = accumulate(b.begin(), b.end(), 0);
    vector<int> diff_ab(n);
    for (int i = 0; i < n; ++i) {
      diff_ab[i] = a[i] - b[i];
    }
    sort(diff_ab.rbegin(), diff_ab.rend());
    tot += accumulate(diff_ab.begin(), diff_ab.begin() + n - y, 0);
    for (int i = n - y; i < x; ++i) {
      if (diff_ab[i] < 0) break;
      tot += diff_ab[i];
    }
    cout << tot << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}