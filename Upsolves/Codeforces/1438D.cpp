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
  vector<array<int, 3>> moves;

  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    } 
  }
 
  void Solve() {
    if (n == 3) {
      cout << "YES\n" << "1\n" << "1 2 3\n";
      return;
    }
    int all_xor = 0;
    for (auto &i : a) {
      all_xor ^= i;
    }
    if (n % 2 == 0) {
      if (all_xor != 0) {
        cout << "NO\n";
        return;
      }
      for (int i = 1; i + 2 < n; i += 2) {
        AddMove(i, i + 1, i + 2);
        AddMove(0, i, i + 1);
      }
    } else {
      for (int cyc = 0; cyc < 2; ++cyc) {
        for (int i = 1; i + 1 < n; i += 2) {
          AddMove(0, i, i + 1);
        }
      }
    }
    assert(int(moves.size()) <= n && is_sorted(a.begin(), a.end()) && a[0] == a[n - 1]);
    cout << "YES\n" << moves.size() << '\n';
    for (auto &[i, j, k] : moves) {
      cout << i << ' ' << j << ' ' << k << '\n';
    }
  }

  void AddMove(int i, int j, int k) {
    int xor_ijk = a[i] ^ a[j] ^ a[k];
    a[i] = a[j] = a[k] = xor_ijk;
    moves.push_back({i + 1, j + 1, k + 1});
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}