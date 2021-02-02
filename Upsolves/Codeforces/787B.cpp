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
  int n, m;
  vector<vector<int>> groups;

  void Read() {
    cin >> n >> m;
    groups.resize(m);
    for (auto &group : groups) {
      int sz;
      cin >> sz;
      group.resize(sz);
      for (auto &i : group) {
        cin >> i;
      }
    }
  }
 
  void Solve() {
    for (auto &group : groups) {
      sort(group.begin(), group.end());
      if (all_of(group.begin(), group.end(), [&](int x) {
            return !binary_search(group.begin(), group.end(), -x);
          })) {
        cout << "YES\n";
        return;
      }
    }
    cout << "NO\n";
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}