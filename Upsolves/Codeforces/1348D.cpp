#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int n;
 
  void Read() {
    cin >> n;
  }
 
  void Solve() {
    vector<int> inc;
    for (int p = 1; p <= n; p *= 2) {
      inc.emplace_back(p);
      n -= p;
    }
    if (n != 0) {
      inc.emplace_back(n);
    }
    sort(inc.begin(), inc.end());
    cout << int(inc.size()) - 1 << "\n";
    for (int i = 1; i < int(inc.size()); ++i) {
      cout << inc[i] - inc[i - 1] << " ";
    }
    cout << "\n";
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}