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
  vector<int> a;

  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    int64_t sum = 0, xor_sum = 0;
    for (auto &i : a) {
      sum += i;
      xor_sum ^= i;
    }
    cout << 2 << "\n" << xor_sum << " " << sum + xor_sum << "\n";
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