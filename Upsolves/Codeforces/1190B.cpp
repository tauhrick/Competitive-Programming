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

  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    if (AlreadyBad()) {
      cout << Win(1) << '\n';
    } else {
      int64_t moves = 0;
      sort(a.begin(), a.end());
      for (int i = 0; i < n; ++i) {
        assert(a[i] >= i);
        moves += a[i] - i;
      }
      cout << Win(1 - int(moves % 2)) << '\n';
    }
  }

  bool AlreadyBad() {
    map<int, int> cnt;
    for (auto &i : a) {
      ++cnt[i];
      if (cnt[i] > 2) return true;
    }
    cnt[-1] = 1;
    int cnt_2 = 0;
    for (auto &i : cnt) {
      if (i.second == 2) {
        ++cnt_2;
        if (cnt.count(i.first - 1)) return true;
      }
    }
    return cnt_2 > 1;
  }

  string Win(int x) {
    return (x == 0 ? "sjfnb" : "cslnb");
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}