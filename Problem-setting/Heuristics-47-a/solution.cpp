#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int x;

  void Read() {
    cin >> x;
  }
 
  void Solve() {
    if (x >= 1) {
      cout << x + 10;
    } else {
      cout << x - 10;
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
  Task t;
  t.Perform();
  return 0;
}