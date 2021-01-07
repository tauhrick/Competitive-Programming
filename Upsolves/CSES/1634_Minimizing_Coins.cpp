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
  int n, x;
  vector<int> coin_values;

  void Read() {
    cin >> n >> x;
    coin_values.resize(n);
    for (auto &c : coin_values) {
      cin >> c;
    }
  }
 
  void Solve() {
    vector<int> coins(x + 1, kInf);
    coins[0] = 0;
    for (int i = 1; i <= x; ++i) {
      for (auto &c : coin_values) {
        if (i - c >= 0 && coins[i - c] != kInf) {
          coins[i] = min(coins[i], coins[i - c] + 1);
        }
      }
    }
    cout << (coins[x] == kInf ? -1 : coins[x]) << "\n";
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