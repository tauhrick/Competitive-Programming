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
  int n, st;  
  vector<int> x;

  void Read() {
    cin >> n >> st;
    x.resize(n);
    for (auto &i : x) {
      cin >> i;
    } 
  }
 
  void Solve() {
    int d = 0;
    for (auto &i : x) {
      d = gcd(d, abs(i - st));
    }
    cout << d << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}