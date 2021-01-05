#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int n, k;
  string s;
 
  void Read() {
    cin >> n >> k >> s;
  }
 
  void Solve() {
    for (auto &ch : s) {
      ch = char(('0' ^ '1' ^ ch) - '0');
    }
    vector<int> pf_zero(n);
    for (int i = 0; i < n; ++i) {
      pf_zero[i] = (s[i] == 0) + (i == 0 ? 0 : pf_zero[i - 1]);
    }
    int bits_store = min(k, int(log2(n - k + 1)) + 2);
    int zeroes = k - bits_store;
    int mx_mask = (1 << bits_store) - 1;
    vector<bool> bad(mx_mask + 1);
    for (int i = 0; i + k - 1 < n; ++i) {
      int zero_cnt = zeroes == 0 ? 0 : (pf_zero[i + zeroes - 1] - (i == 0 ? 0 : pf_zero[i - 1]));
      if (zero_cnt == zeroes) {
        int mask = 0;
        for (int j = i + zeroes; j < i + k; ++j) {
          mask = (mask << 1) | s[j];
        }
        bad[mask] = true;
      }
    }
    for (int i = 0; i <= mx_mask; ++i) {
      if (!bad[i]) {
        cout << "YES\n" << string(zeroes, '0');
        for (int bit = bits_store - 1; bit >= 0; --bit) {
          cout << ((i >> bit) & 1);
        }
        cout << "\n";
        return;
      }
    }
    cout << "NO\n";
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