#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  static const int kMod = int(1e9) + 7;

  int n;

  void Read() {
    cin >> n;
  }
 
  void Solve() {
    vector<int> ways(n + 1);
    ways[0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= 6 && i - j >= 0; ++j) {
        ways[i] += ways[i - j];
        ways[i] %= kMod;
      }
    }
    cout << ways[n] << "\n";
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