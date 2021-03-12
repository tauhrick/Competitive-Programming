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
  int64_t n;

  void Read() {
    cin >> n;
  }
 
  void Solve() {
    set<int64_t> seen;
    for (int a = 2; a <= int(sqrt(n)); ++a) {
      int64_t st = int64_t(a) * a;
      while (st <= n) {
        seen.insert(st);
        st *= a;
      }
    }
    cout << n - int(seen.size()) << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}