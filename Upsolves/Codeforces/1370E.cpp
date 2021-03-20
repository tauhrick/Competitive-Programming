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
  string s, t;

  void Read() {
    cin >> n >> s >> t;
  }
 
  void Solve() {
    auto inds = vector(4, set<int>{});
    for (int i = 0; i < n; ++i) {
      int h = GetHash(s[i], t[i]);
      inds[h].insert(i);
    }
    if (inds[1].size() != inds[2].size()) {
      cout << "-1\n";
      return;
    }
    int moves = 0;
    while (min(inds[1].size(), inds[2].size()) > 0) {
      ++moves;
      int turn = (*inds[1].begin() < *inds[2].begin() ? 0 : 1);
      int prv = -1;
      while (true) {
        auto it_1 = inds[1 + turn].lower_bound(prv);
        if (it_1 == inds[1 + turn].end()) break;
        auto it_2 = inds[1 + !turn].lower_bound(*it_1);
        if (it_2 == inds[1 + !turn].end()) break;
        prv = *it_2;
        inds[1 + turn].erase(it_1);
        inds[1 + !turn].erase(it_2);
      }
    }
    cout << moves << '\n';
  }

  int GetHash(char b0, char b1) {
    return ((b1 - '0') << 1) + (b0 - '0');
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}