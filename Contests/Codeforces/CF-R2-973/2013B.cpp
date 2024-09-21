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
  int n;
  std::vector<int> a;

  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }

  void Solve() {
    int64_t ans = a[n - 1] - a[n - 2];
    for (int i = n - 3; i >= 0; --i) {
      ans += a[i];
    }
    cout << ans << '\n';
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
