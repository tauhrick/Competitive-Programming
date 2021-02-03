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
  vector<int> c;
  vector<int> t;

  void Read() {
    cin >> n;
    c.resize(n);
    for (auto &i : c) {
      cin >> i;
    }
    t.resize(n);
    for (auto &i : t) {
      cin >> i;
    }
  }
 
  void Solve() {
    vector<int> df_c(n);
    vector<int> df_t(n);
    for (int i = 1; i < n; ++i) {
      df_c[i] = c[i] - c[i - 1];
      df_t[i] = t[i] - t[i - 1];
    }
    sort(df_c.begin(), df_c.end());
    sort(df_t.begin(), df_t.end());
    if (df_c == df_t && c[0] == t[0] && c[n - 1] == t[n - 1]) {
      cout << "Yes";
    } else {
      cout << "No";
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