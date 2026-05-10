#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "/Users/mac-mini/Desktop/CP/Library/Debug.hpp"
#endif

const int64_t kInf = 3e18;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }

 private:
  int n;
  int64_t k;
  vector<int64_t> a;

  void Read() {
    cin >> n >> k;
    a.resize(n);
    for (auto& i : a) {
      cin >> i;
    }
  }

  void Solve() {
    int64_t lo = *min_element(a.begin(), a.end());
    int64_t hi = kInf;
    while (lo < hi) {
      int64_t mid = lo + ((hi - lo + 1) / 2);
      if (IsPossible(mid)) {
        lo = mid;
      } else {
        hi = mid - 1;
      }
    }
    cout << lo << '\n';
  }

  bool IsPossible(int64_t x) {
    int64_t moves = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] >= x) {
        continue;
      }
      int64_t req = x - a[i];
      int step = i + 1;
      moves += (req + step - 1) / step;
      if (moves > k) {
        return false;
      }
    }
    return true;
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
