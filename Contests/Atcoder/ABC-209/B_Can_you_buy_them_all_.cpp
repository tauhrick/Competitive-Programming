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
  int n, x;  
  vector<int> a;

  void Read() {
    cin >> n >> x; 
    a.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
      if (i & 1) {
        --a[i];
      }
    }
  }
 
  void Solve() {
    cout << (accumulate(a.begin(), a.end(), 0) <= x ? "Yes" : "No") << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}