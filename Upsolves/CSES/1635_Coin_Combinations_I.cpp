#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

const int kMod = int(1e9) + 7;

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
    sort(coin_values.begin(), coin_values.end());
    coin_values.resize(unique(coin_values.begin(), coin_values.end()) - coin_values.begin());
    vector<int> ways(x + 1);
    ways[0] = 1;
    for (int i = 1; i <= x; ++i) {
      for (int j = 0; j < int(coin_values.size()) && i - coin_values[j] >= 0; ++j) {
        ways[i] += ways[i - coin_values[j]];
        ways[i] %= kMod;
      }
    }
    cout << ways[x] << "\n";
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