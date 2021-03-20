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
  string x;  

  void Read() {
    cin >> x; 
  }
 
  void Solve() {
    for (int i = 0; i < int(x.size()); ++i) {
      if (x[i] == '.') break;
      cout << x[i];
    }
    cout << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}