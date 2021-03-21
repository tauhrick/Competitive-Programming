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
  int n, k;
  string s; 

  void Read() {
    cin >> n >> k >> s; 
  }
 
  void Solve() {
    int curr = 0;
    for (int i = 1; i <= n / 2; ++i) {
      curr += s[i - 1] != s[n - i];
    }
    cout << abs(curr - k) << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    cout << "Case #" << tt << ": ";
    Task t;
    t.Perform();
  }
  return 0;
}