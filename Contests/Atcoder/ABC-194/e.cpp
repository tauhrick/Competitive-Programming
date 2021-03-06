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
  vector<int> a;
  map<int, int> taken_cnt;
  set<int> not_taken;

  void Read() {
    cin >> n >> m;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    for (int i = 0; i <= m; ++i) {
      not_taken.insert(i);
    }
    for (int i = 0; i < m; ++i) {
      Insert(i);
    }
    int res = *not_taken.begin();
    for (int i = m; i < n; ++i) {
      Insert(i);
      Remove(i - m);
      res = min(res, *not_taken.begin());
    }
    cout << res << '\n';
  }

  void Insert(int ind) {
    if (!taken_cnt.count(a[ind])) {
      not_taken.erase(a[ind]);
    }
    ++taken_cnt[a[ind]];
  }

  void Remove(int ind) {
    --taken_cnt[a[ind]];
    if (taken_cnt[a[ind]] == 0) {
      taken_cnt.erase(a[ind]);
      not_taken.insert(a[ind]);
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}