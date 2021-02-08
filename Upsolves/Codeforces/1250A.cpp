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
  vector<int> likes;

  void Read() {
    cin >> n >> m;
    likes.resize(m);
    for (auto &i : likes) {
      cin >> i;
    }
  }
 
  void Solve() {
    vector<int> lo(n + 1);
    vector<int> hi(n + 1);
    vector<int> pos(n + 1);
    vector<int> order(n + 1);
    for (int i = 1; i <= n; ++i) {
      lo[i] = hi[i] = pos[i] = order[i] = i;
    }
    for (auto &like : likes) {
      int ind = pos[like];
      if (ind == 1) continue;
      int prv_post = order[ind - 1];
      swap(order[ind - 1], order[ind]);
      swap(pos[like], pos[prv_post]);
      for (auto &post : {like, prv_post}) {
        lo[post] = min(lo[post], pos[post]);
        hi[post] = max(hi[post], pos[post]);
      }
    }
    for (int i = 1; i <= n; ++i) {
      cout << lo[i] << ' ' << hi[i] << '\n';
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}