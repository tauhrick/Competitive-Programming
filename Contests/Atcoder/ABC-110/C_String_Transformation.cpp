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
  string s, t; 

  void Read() {
    cin >> s >> t; 
  }
 
  void Solve() {
    map<char, vector<int>> pos_t;
    for (int i = 0; i < int(t.size()); ++i) {
      pos_t[t[i]].push_back(i);
    }
    map<char, vector<int>> pos_s;
    for (int i = 0; i < int(s.size()); ++i) {
      pos_s[s[i]].push_back(i);
    }
    for (auto &[_, p] : pos_t) {
      char tar = s[p[0]];
      if (p != pos_s[tar]) {
        cout << "No\n";
        return;
      }
    }
    cout << "Yes\n";
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}