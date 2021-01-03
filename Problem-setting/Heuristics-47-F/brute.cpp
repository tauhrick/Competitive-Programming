#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int n, q;
  vector<int> a;
  vector<pair<int, int>> queries;

  void Read() {
    cin >> n >> q;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
    queries.resize(q);
    for (auto &[l, r] : queries) {
      cin >> l >> r;
      if (r < l) {
        r += n;
      }
      --l, --r;
    }
  }
 
  void Solve() {
    for (int i = 0; i < n; ++i) {
      a.emplace_back(a[i]);
    }
    for (auto &[l, r] : queries) {
      map<int, int> cnt;
      for (int i = l; i <= r; ++i) {
        ++cnt[a[i]];
      }
      int ans = 0;
      for (auto p : cnt) {
        ans += (p.second % 2 == 0);
      }
      cout << ans << "\n";
    }
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