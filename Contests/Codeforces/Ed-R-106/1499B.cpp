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
  string s; 

  void Read() {
    cin >> s;
  }
 
  void Solve() {
    bool two_ones = false;
    for (int i = 0; i + 1 < int(s.size()); ++i) {
      two_ones |= s[i] == '1' && s[i + 1] == '1';
      if (two_ones && s[i] == '0' && s[i + 1] == '0') {
        cout << "NO\n";
        return;
      }
    }
    cout << "YES\n";
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