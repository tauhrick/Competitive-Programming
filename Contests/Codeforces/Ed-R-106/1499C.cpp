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
  vector<int> c; 

  void Read() {
    cin >> n;
    c.resize(n);
    for (auto &i : c) {
      cin >> i;
    } 
  }

  vector<multiset<int>> vals;
  vector<int64_t> sums;
 
  void Solve() {
    vals = vector(2, multiset<int>{});
    sums = vector(2, int64_t(0));
    Add(0), Add(1);
    int64_t best = int64_t(n) * (c[0] + c[1]);
    for (int i = 2; i < n; ++i) {
      Add(i);
      int64_t curr = 0;
      for (auto &seq : {0, 1}) {
        int min_seq = *vals[seq].begin();
        curr += int64_t(min_seq) * (n - (int(vals[seq].size()) - 1));
        curr += sums[seq] - min_seq;
      }
      best = min(best, curr);
    }
    cout << best << '\n';
  }

  void Add(int ind) {
    vals[ind & 1].insert(c[ind]);
    sums[ind & 1] += c[ind];
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