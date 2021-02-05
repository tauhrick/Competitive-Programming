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
  vector<string> rows;

  void Read() {
    cin >> n;
    rows.resize(n);
    for (auto &row : rows) {
      cin >> row;
    }
  }
 
  void Solve() {
    string tar = "OO";
    bool fnd = false;
    for (auto &row : rows) {
      if (row.substr(0, 2) == tar) {
        row[0] = row[1] = '+';
        fnd = true;
        break;
      } else if (row.substr(3, 2) == tar) {
        row[3] = row[4] = '+';
        fnd = true;
        break;
      }
    }
    if (!fnd) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (auto &row : rows) {
        cout << row << '\n';
      }
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}