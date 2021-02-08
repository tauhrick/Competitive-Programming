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
    vector<int> placed_people;
    int best = 0;
    for (int i = 1; i <= n; ++i) {
      int pos;
      if (a[i - 1] == 0) {
        pos = 0;
      } else {
        pos = int(find(placed_people.begin(), placed_people.end(), a[i - 1]) - 
                      placed_people.begin()) + 1;
      }
      best += min(pos, int(placed_people.size()) - pos);
      placed_people.insert(placed_people.begin() + pos, i);
    }
    cout << best << '\n';
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