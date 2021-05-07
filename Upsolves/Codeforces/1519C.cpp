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
  vector<int> u, s; 

  void Read() {
    cin >> n;
    u.resize(n); 
    for (auto &i : u) {
      cin >> i;
    }
    s.resize(n);
    for (auto &i : s) {
      cin >> i;
    }
  }
 
  void Solve() {
    vector students(n + 1, vector(1, int64_t(0)));
    for (int i = 0; i < n; ++i) {
      students[u[i]].push_back(s[i]);
    }
    vector<int64_t> ans(n + 1);
    for (int i = 1; i <= n; ++i) {
      sort(students[i].rbegin(), students[i].rend() - 1);
      int sz = int(students[i].size()) - 1;
      for (int j = 1; j <= sz; ++j) {
        students[i][j] += students[i][j - 1];
      }
      for (int k = 1; k <= sz; ++k) {
        int rem = sz % k;
        ans[k] += students[i][sz] - (students[i][sz] - students[i][sz - rem]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      cout << ans[i] << " \n"[i == n];
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