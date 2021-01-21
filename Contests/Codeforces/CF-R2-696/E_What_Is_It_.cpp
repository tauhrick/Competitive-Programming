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
  vector<int> perm;
  vector<pair<int, int>> moves;
  int64_t cost = 0;

  void Read() {
    cin >> n;
  }
 
  void Solve() {
    perm.resize(n + 1);
    iota(perm.begin(), perm.end(), 0);
    Move(1, n);
    for (int i = 2; i <= n - i + 1; ++i) {
      Move(i, n);
      if (n - i + 1 > i) {
        Move(n - i + 1, 1);
      }
    }
    reverse(moves.begin(), moves.end());
    cout << cost << "\n";
    for (int i = 1; i <= n; ++i) {
      cout << perm[i] << " \n"[i == n];
    }
    cout << moves.size() << "\n";
    for (auto &move : moves) {
      cout << move.first << " " << move.second << "\n";
      swap(perm[move.first], perm[move.second]);
    }
    assert(is_sorted(perm.begin(), perm.end()));
  }

  void Move(int i, int j) {
    swap(perm[i], perm[j]);
    moves.emplace_back(i, j);
    cost += Square(i - j);
  }

  int64_t Square(int64_t x) {
    return x * x;
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