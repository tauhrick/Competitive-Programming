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
  vector<vector<int>> inds;
  vector<vector<int>> prv;
  int ans = 0;

  void Read() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
  }
 
  void Solve() {
    inds.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
      inds[a[i]].push_back(i);
    }
    prv = vector(2, vector(1, 0));
    for (int i = 1; i <= n; ++i) {
      if (a[i] == prv[0].back()) {
        Add(1, a[i]);
      } else if (a[i] == prv[1].back()) {
        Add(0, a[i]);
      } else {
        vector<int> nxt(2);
        for (int j = 0; j < 2; ++j) {
          auto &locations = inds[prv[j].back()];
          int loc = int(lower_bound(locations.begin(), locations.end(), i) - 
                        locations.begin());
          if (loc == int(locations.size())) {
            nxt[j] = n + 1;
          } else {
            nxt[j] = locations[loc];
          }
        }
        if (nxt[0] < nxt[1]) {
          Add(0, a[i]);
        } else {
          Add(1, a[i]);
        }
      }
    }
    cout << ans << '\n';
  }

  void Add(int v, int el) {
    if (!prv[v].empty() && prv[v].back() != el) {
      ++ans;
    }
    prv[v].push_back(el);
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}