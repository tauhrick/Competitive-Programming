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
  vector<pair<int64_t, int64_t>> v;
  int64_t d;

  void Read() {
    cin >> n;
    v.resize(n);
    d = 0;
    for (auto &[a, b] : v) {
      cin >> a >> b;
      d += a;
    }
  }
 
  void Solve() {
    sort(v.begin(), v.end(), [&](auto ll, auto rr) -> bool {
      return -2 * ll.first - ll.second < -2 * rr.first - rr.second;
    });
    for (int i = 0; i <= n; ++i) {
      if (d < 0) {
        cout << i << "\n";
        return;
      }
      if (i != n) {
        d += -2 * v[i].first - v[i].second;
      }
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