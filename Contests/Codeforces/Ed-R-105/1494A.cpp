#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const vector brac = {-1, 1};

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  string s;

  void Read() {
    cin >> s;
  }
 
  void Solve() {
    for (auto a : brac) {
      for (auto b : brac) {
        for (auto c : brac) {
          int ctr = 0;
          for (auto &ch : s) {
            if (ch == 'A') {
              ctr += a;
            } else if (ch == 'B') {
              ctr += b;
            } else {
              ctr += c;
            }
            if (ctr < 0) break;
          }
          if (ctr == 0) {
            cout << "YES\n";
            return;
          }
        }
      }
    }
    cout << "NO\n";
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