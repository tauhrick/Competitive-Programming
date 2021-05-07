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

  void Read() {
    cin >> n; 
  }
 
  void Solve() {
    vector<int> ans(n + 1, -1);
    ans[1] = CalculateNumber();
    int mid = n / 2;
    int extreme_index = 1;
    for (int i = 2; i <= n; ++i) {
      if (ans[extreme_index] == 1) {
        ans[i] = Ask(1, n - 1, extreme_index, i);
      } else if (ans[extreme_index] == n) {
        ans[i] = Ask(2, 1, i, extreme_index);
      } else {
        if (ans[extreme_index] <= mid) {
          int val = Ask(1, n - 1, extreme_index, i);
          if (val == ans[extreme_index]) {
            ans[i] = Ask(2, 1, i, extreme_index);
          } else {
            ans[i] = val;
          }
        } else {
          int val = Ask(2, 1, i, extreme_index);
          if (val == ans[extreme_index]) {
            ans[i] = Ask(1, n - 1, extreme_index, i);
          } else {
            ans[i] = val;
          }
        }
        if (EdgeDist(ans[i]) < EdgeDist(ans[extreme_index])) {
          extreme_index = i;
        }
      }
    }
    cout << "! ";
    for (int i = 1; i <= n; ++i) {
      cout << ans[i] << ' ';
    }
    cout << endl;
  }

  int CalculateNumber() {
    if (Ask(1, n - 1, n, 1) == n) {
      return n;
    }
    int lo = 1, hi = n - 1;
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      if (Ask(2, mid, 1, n) == mid) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    return lo;
  }

  int Ask(int typ, int x, int i, int j) {
    cout << "? " << typ << ' ' << i << ' ' << j << ' ' << x << endl;
    int resp;
    cin >> resp;
    return resp;
  }

  int EdgeDist(int x) {
    return min(abs(1 - x), abs(n - x));
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}