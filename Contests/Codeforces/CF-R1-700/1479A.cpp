#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kInf = INT_MAX;

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
    auto a = vector(n + 2, kInf);
    auto seen = vector(n + 2, false);
    seen[0] = seen[n + 1] = true;
    int lo = 1, hi = n;
    while (lo < hi) {
      int mid = lo + ((hi - lo) >> 1);
      for (auto ind : {mid, mid + 1}) {
        if (!seen[ind]) {
          seen[ind] = true;
          cout << "? " << ind << endl;
          cin >> a[ind];
        }
      }
      if (a[mid] < a[mid + 1]) {
        hi = mid;
      } else {
        lo = mid + 1;
      }
    }
    cout << "! " << lo << endl;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}