#include <atcoder/modint>

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
  using Mint = atcoder::modint1000000007;

  int n;
  vector<int> c;  

  void Read() {
    cin >> n;
    c.resize(n);
    for (auto &i : c) {
      cin >> i;
    }
  }
 
  void Solve() {
    sort(c.begin(), c.end());
    Mint res = 1;
    for (int i = 0; i < n; ++i) {
      res *= max(0, c[i] - i);
    }
    cout << res.val() << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}