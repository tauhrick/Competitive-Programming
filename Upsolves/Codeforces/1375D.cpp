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
  vector<int> moves;

  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    set<int> bad_pos;
    for (int i = 0; i < n; ++i) {
      if (a[i] != i) {
        bad_pos.emplace(i);
      }
    }
    while (!bad_pos.empty()) {
      int mex_a = GetMex();
      if (mex_a == n) {
        Move(*bad_pos.begin(), mex_a);
      } else {
        Move(mex_a, mex_a);
        bad_pos.erase(mex_a);
      }
    }
    assert(int(moves.size()) <= 2 * n);
    cout << moves.size() << "\n";
    for (auto &move : moves) {
      cout << move << " ";
    }
    cout << "\n";
  }

  void Move(int loc, int mex_a) {
    moves.emplace_back(loc + 1);
    a[loc] = mex_a;
  }

  int GetMex() {
    vector<int> cnt(n + 1);
    for (auto &i : a) {
      ++cnt[i];
    }
    for (int i = 0; i <= n; ++i) {
      if (cnt[i] == 0) {
        return i;
      }
    }
    return -1;
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