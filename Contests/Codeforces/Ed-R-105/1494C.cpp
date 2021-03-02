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
  vector<int> a;
  vector<int> b;
  vector<int> pf;
  vector<int> sf;

  void Read() {
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    b.resize(m);
    for (auto &i : b) {
      cin >> i;
    }
  }
 
  void Solve() {
    pf.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      pf[i] = pf[i - 1] + binary_search(b.begin(), b.end(), a[i]);
    }
    sf.resize(n + 2);
    for (int i = n; i >= 1; --i) {
      sf[i] = sf[i + 1] + binary_search(b.begin(), b.end(), a[i]);
    }
    int st_a = int(lower_bound(a.begin() + 1, a.end(), 0) - a.begin());
    int st_b = int(lower_bound(b.begin(), b.end(), 0) - b.begin());
    cout << SolvePositive(st_a, st_b) + SolveNegative(st_a - 1, st_b - 1) << '\n';
  }

  int SolvePositive(int i_a, int i_b) {
    int best = sf[i_a];
    for (int boxes = 0; i_b < m; ++i_b) {
      while (i_a <= n && a[i_a] <= b[i_b] + boxes - 1) {
        ++i_a;
        ++boxes;
      }
      int j_b = int(upper_bound(b.begin(), b.end(), b[i_b] + boxes - 1) - b.begin()) - 1;
      best = max(best, j_b - i_b + 1 + sf[i_a]);
    }
    return best;
  }

  int SolveNegative(int i_a, int i_b) {
    int best = pf[i_a];
    for (int boxes = 0; i_b >= 0; --i_b) {
      while (i_a > 0 && a[i_a] >= b[i_b] - boxes + 1) {
        --i_a;
        ++boxes;
      }
      int j_b = int(lower_bound(b.begin(), b.end(), b[i_b] - boxes + 1) - b.begin());
      best = max(best, i_b - j_b + 1 + pf[i_a]);
    }
    return best;
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