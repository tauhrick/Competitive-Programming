#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int a, b;

  void Read() {
    cin >> a >> b;
  }
 
  void Solve() {
    cout << max(Get(a), Get(b)) << "\n";
  }

  int Get(int x) {
    int sum = 0;
    while (x != 0) {
      sum += x % 10;
      x /= 10;
    }
    return sum;
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