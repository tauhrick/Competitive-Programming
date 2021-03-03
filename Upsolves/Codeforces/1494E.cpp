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
  map<pair<int, int>, char> edges;

  void Read() {
    cin >> n >> m;
  }
 
  void Solve() {
    int pairs = 0, same_pairs = 0;
    while (m--) {
      char typ;
      cin >> typ;
      if (typ == '+') {
        int u, v;
        char e;
        cin >> u >> v >> e;
        if (edges.count({v, u})) {
          ++pairs;
          same_pairs += edges[{v, u}] == e;
        }
        edges[{u, v}] = e;
      } else  if (typ == '-') {
        int u, v;
        cin >> u >> v;
        if (edges.count({v, u})) {
          --pairs;
          same_pairs -= edges[{v, u}] == edges[{u, v}];
        }
        edges.erase({u, v});
      } else {
        int k;
        cin >> k;
        cout << ((k % 2 == 1 ? pairs : same_pairs) > 0 ? "YES" : "NO") << '\n';
      }
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}