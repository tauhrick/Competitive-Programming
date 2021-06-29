#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kA = 16;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n, m;  
  vector<vector<int>> a;
  int lcm_all;
  vector<int> pow_4;

  void Read() {
    cin >> n >> m;
    a = vector(n, vector(m, 0)); 
    for (auto &row : a) {
      for (auto &i : row) {
        cin >> i;
      }
    }
  }
 
  void Solve() {
    Pre();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if ((i + j) & 1) {
          cout << lcm_all;
        } else {
          cout << lcm_all - pow_4[a[i][j]];
        }
        cout << ' ';
      }
      cout << '\n';
    }
  }

  void Pre() {
    lcm_all = 1;
    pow_4.resize(kA + 1);
    for (int i = 1; i <= 16; ++i) {
      lcm_all = lcm(lcm_all, i);
      pow_4[i] = i * i * i * i;
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}