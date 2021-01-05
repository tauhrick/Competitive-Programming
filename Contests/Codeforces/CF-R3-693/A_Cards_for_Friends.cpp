#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int w, h, n;
 
  void Read() {
    cin >> w >> h >> n;
  }
 
  void Solve() {
    cout << (Get(w) * Get(h) >= n ? "YES" : "NO") << "\n";
  }

  int Get(int x) {
    int foo = x;
    while (x % 2 == 0) {
      x /= 2;
    }
    return foo / x;
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}