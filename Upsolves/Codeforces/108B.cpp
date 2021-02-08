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
    sort(a.begin(), a.end());
    for (int i = 1; i < n; ++i) {
      if (a[i] > a[i - 1] && 2 * a[i - 1] > a[i]) {
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