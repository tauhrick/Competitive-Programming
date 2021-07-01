#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kB = 22;
const int kM = (1 << kB) - 1;

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
    vector pos(kM + 1, -1);
    for (int i = 0; i < n; ++i) {
      pos[a[i]] = i;
    }
    for (int mask = 1; mask <= kM; ++mask) {
      for (int j = 0; j < kB; ++j) {
        if ((mask >> j) & 1) {
          pos[mask] = max(pos[mask], pos[mask ^ (1 << j)]);
        }
      }
    }
    for (auto &i : a) {
      int neg_i = (~i) & kM;
      cout << (pos[neg_i] == -1 ? -1 : a[pos[neg_i]]) << ' ';
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