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
    map<int, int> cnt;
    for (auto &i : a) {
      ++cnt[i];
    }
    int64_t res = int64_t(n) * n;
    for (auto &i : cnt) {
      res -= int64_t(i.second) * i.second;
    }
    res /= 2;
    cout << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}