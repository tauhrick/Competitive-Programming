#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

const int kInf = INT_MAX;

class Task {
 private:
  int n;

  void Read() {
    cin >> n;
  }
 
  void Solve() {
    vector<int> steps(n + 1, kInf);
    steps[0] = 0;
    for (int i = 1; i <= n; ++i) {
      int foo = i;
      while (foo != 0) {
        if (foo % 10 != 0) {
          steps[i] = min(steps[i], steps[i - (foo % 10)] + 1);
        }
        foo /= 10;
      }
    }
    cout << steps[n] << "\n";
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Task t;
  t.Perform();
  return 0;
}