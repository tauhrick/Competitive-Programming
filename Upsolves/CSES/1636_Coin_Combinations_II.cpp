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
    coin_values.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> coin_values[i];
    }
  }
 
  void Solve() {
    sort(coin_values.begin(), coin_values.end());
    coin_values.resize(unique(coin_values.begin(), coin_values.end()) - coin_values.begin());
    n = int(coin_values.size());
    vector<int> ways(x + 1);
    ways[0] = 1;
    for (int j = 1; j < n; ++j) {
      vector<int> new_ways(x + 1);
      new_ways[0] = 1;
      for (int i = 1; i <= x; ++i) {
        new_ways[i] += ways[i];
        new_ways[i] %= kMod;
        if (i - coin_values[j] >= 0) {
          new_ways[i] += new_ways[i - coin_values[j]];
          new_ways[i] %= kMod;
        }
      }
      ways = new_ways;
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