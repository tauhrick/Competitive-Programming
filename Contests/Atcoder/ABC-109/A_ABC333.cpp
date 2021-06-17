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
  int a, b;  

  void Read() {
    cin >> a >> b; 
  }
 
  void Solve() {
    cout << (a % 2 == 1 && b % 2 == 1 ? "Yes" : "No") << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}