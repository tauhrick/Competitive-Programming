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
    int min_index = int(min_element(a.begin(), a.end()) - a.begin());
    vector<tuple<int, int, int, int>> ans;
    for (int i = 0; i < n; ++i) {
      if (i == min_index) continue;
      int diff = abs(min_index - i);
      int tar = (diff % 2 == 0 ? 0 : 1) + a[min_index];
      ans.emplace_back(min_index, i, a[min_index], tar);
    }
    cout << ans.size() << '\n';
    for (auto &[i, j, x, y] : ans) {
      cout << i + 1 << ' ' << j + 1 << ' ' << x << ' ' << y << '\n';
    }
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