#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
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

  vector<vector<int>> inds;
 
  void Solve() {
    inds.resize(2);
    for (int i = 0; i < n; ++i) {
      inds[a[i] % 2].push_back(i);
    }
    int64_t min_moves = min(TryPlacement(0), TryPlacement(1));
    if (min_moves == INT64_MAX) {
      min_moves = -1;
    }
    cout << min_moves << '\n';
  }

  int64_t TryPlacement(int p) {
    int req_cnt = (n + 1) / 2;
    if (int(inds[p].size()) != req_cnt) {
      return INT64_MAX;
    }
    int64_t moves = 0;
    for (int i = 0; i < req_cnt; ++i) {
      moves += abs(2 * i - inds[p][i]);
    }
    return moves;
  }
 
 public:
  void Perform() {
    Read();
    Solve();
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
