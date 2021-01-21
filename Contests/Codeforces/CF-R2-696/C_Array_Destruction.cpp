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

  void Read() {
    cin >> n;
    m = 2 * n;
    a.resize(m);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    sort(a.begin(), a.end());
    for (int take = m - 2; take >= 0; --take) {
      vector<pair<int, int>> moves;
      map<int, int> cnt;
      for (auto &i : a) {
        ++cnt[i];
      }
      int x = a[take] + a[m - 1];
      bool bad = false;
      for (int i = m - 1; i >= 0; --i) {
        if (cnt[a[i]] == 0) continue;
        int prv = x - a[i];
        moves.emplace_back(a[i], prv);
        --cnt[a[i]], --cnt[prv];
        if (cnt[a[i]] < 0 || cnt[prv] < 0) {
          bad = true;
          break;
        }
        x = a[i];
      }
      if (!bad) {
        assert(int(moves.size()) == n);
        cout << "YES\n" << a[take] + a[m - 1] << "\n";
        for (auto &p : moves) {
          cout << p.first << " " << p.second << "\n";
        }
        return;
      }
    }
    cout << "NO\n";
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}