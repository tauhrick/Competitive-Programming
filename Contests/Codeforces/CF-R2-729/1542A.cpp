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
    a.resize(2 * n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    int even = 0, odd = 0;
    for (auto &i : a) {
      if (i & 1) {
        ++odd;
      } else {
        ++even;
      }
    }
    cout << (even == odd ? "Yes" : "No") << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  } 
  return 0;
}