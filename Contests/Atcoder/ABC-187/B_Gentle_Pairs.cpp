#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int n;
  vector<int> x, y;

  void Read() {
    cin >> n;
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }
  }
 
  void Solve() {
    int pairs = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int dy = y[j] - y[i];
        int dx = x[j] - x[i];
        if (dx < 0) {
          dx = -dx;
          dy = -dy;
        }
        if (-dx <= dy && dy <= dx) {
          ++pairs;
        }
      }
    }
    cout << pairs << "\n";
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