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
    int price = int(1.08 * n);
    if (price < 206) {
      cout << "Yay!";
    } else if (price > 206) { 
      cout << ":(";
    } else {
      cout << "so-so";
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