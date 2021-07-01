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
  int n, c;  
  vector<int> a;

  void Read() {
    cin >> n >> c;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    } 
  }
 
  void Solve() {
    vector<int> pf(n + 1);
    map<int, vector<int>> inds;
    for (int i = 1; i <= n; ++i) {
      pf[i] = pf[i - 1] + (a[i] == c);
      inds[a[i]].push_back(i);
    }
    int res = INT_MIN;
    for (auto &[_, v] : inds) {
      set<int> mn_pq;
      for (int i = 0; i < int(v.size()); ++i) {
        mn_pq.insert(i - pf[v[i] - 1]);
        res = max(res, pf[n] + (i - pf[v[i]]) - *mn_pq.begin() + 1);
      }
    }
    cout << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}