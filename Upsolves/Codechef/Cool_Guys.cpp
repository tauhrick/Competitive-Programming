/*
Count values of i such that floor(N/i) = x
N/i >= x  ==>  N/x >= i  ==>   i <= floor(N/x)
N/i < x + 1  ==>  N/(x + 1) < i  ==>  i >= floor(N/(x + 1)) + 1
*/

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
    int64_t total = 1LL * n * n;
    int64_t good = 0;
    int sqrt_n = int(sqrt(n));
    for (int i = 1; i <= sqrt_n; ++i) {
      good += n / i;
      int st = max(sqrt_n + 1, n / (i + 1) + 1);
      int en = n / i;
      good += 1LL * i * max(0, en - st + 1);
    }
    int64_t g = __gcd(good, total);
    good /= g;
    total /= g;
    cout << good << "/" << total << "\n";
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}
