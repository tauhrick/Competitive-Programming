#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kInf = 100;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n;
  vector<int> x;

  void Read() {
    cin >> n;
    x.resize(n);
    for (auto &i : x) {
      cin >> i;
    }
  }
 
  void Solve() {
    int min_infected = kInf;
    int max_infected = -kInf;
    for (int st = 0; st < n; ++st) {
      vector<int> infected_set = {x[st]};
      auto is_infected = vector(n, false);
      is_infected[st] = true;
      for (int moves = 0; moves < n; ++moves) {
        for (int i = 0; i < n; ++i) {
          if (!is_infected[i]) {
            for (auto &source : infected_set) {
              if (abs(source - x[i]) <= 2) {
                is_infected[i] = true;
                infected_set.push_back(x[i]);
                break;
              }
            }
          }
        }
      }
      min_infected = min(min_infected, int(infected_set.size()));
      max_infected = max(max_infected, int(infected_set.size()));
    }
    cout << min_infected << ' ' << max_infected << '\n';
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