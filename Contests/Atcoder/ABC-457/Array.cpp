#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "/Users/mac-mini/Desktop/CP/Library/Debug.hpp"
#endif

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }

 private:
  int n, x;
  vector<int> a;

  void Read() {
    cin >> n;
    a.resize(n);
    for (auto& i : a) {
      cin >> i;
    }
    cin >> x;
  }

  void Solve() { cout << a[x - 1] << '\n'; }
};

int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc = 1;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}
