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
  int n, k;
  vector<pair<int, int>> segments;

  void Read() {
    cin >> n >> k;
    segments.resize(n);
    for (auto &[l, r] : segments) {
      cin >> l >> r;
    }
  }
 
  void Solve() {
    vector<pair<int, int>> updates;
    for (int i = 0; i < n; ++i) {
      updates.emplace_back(segments[i].first, i + 1);
      updates.emplace_back(segments[i].second + 1, -(i + 1));
    }
    sort(updates.begin(), updates.end());
    auto erased = vector(n + 1, false);
    int erased_count = 0;
    set<pair<int, int>> active_segments;
    for (int i = 0, j = 0; i < int(updates.size()); i = j) {
      while (j < int(updates.size()) && updates[j].first == updates[i].first) {
        int ind = abs(updates[j].second) - 1;
        if (updates[j].second > 0) {
          active_segments.insert({-segments[ind].second, ind});
        } else {
          active_segments.erase({-segments[ind].second, ind});
        }
        ++j;
      }
      while (int(active_segments.size()) > k) {
        auto [_, ind] = *active_segments.begin();
        erased[ind] = true;
        ++erased_count;
        active_segments.erase(active_segments.begin());
      }
    }
    cout << erased_count << '\n';
    for (int i = 0; i < n; ++i) {
      if (erased[i]) {
        cout << i + 1 << ' ';
      }
    }
    cout << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}