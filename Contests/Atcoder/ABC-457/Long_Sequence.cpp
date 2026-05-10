#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "/Users/mac-mini/Desktop/CP/Library/Debug.hpp"
#endif

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }

 private:
  int n;
  int64_t k;
  vector<vector<int>> a;
  vector<int> c;

  void Read() {
    cin >> n >> k;
    a.resize(n);
    for (int r = 0; r < n; r++) {
      int l;
      cin >> l;
      a[r].resize(l);
      for (auto& j : a[r]) {
        cin >> j;
      }
    }
    c.resize(n);
    for (auto& i : c) {
      cin >> i;
    }
  }

  void Solve() {
    int64_t ctr = 0;
    for (int r = 0; r < n; r++) {
      int64_t to_add = 1LL * c[r] * a[r].size();
      int64_t left = k - ctr;
      if (to_add < left) {
        ctr += to_add;
        continue;
      }
      cout << a[r][(left - 1) % a[r].size()] << '\n';
      break;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc = 1;
  // cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}
