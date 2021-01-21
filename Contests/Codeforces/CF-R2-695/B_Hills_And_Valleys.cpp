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
  vector<int> a;

  void Read() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
  }
 
  void Solve() {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
      int prv = Get(i - 1, i + 1);
      int curr = prv;
      auto Try = [&](int val) {
        int foo = a[i];
        a[i] = val;
        curr = min(curr, Get(i - 1, i + 1));
        a[i] = foo;
      };
      if (i + 1 <= n) {
        Try(a[i + 1] + 1);
        Try(a[i + 1] - 1);
        Try(a[i + 1]);
      }
      if (i - 1 >= 1) {
        Try(a[i - 1] + 1);
        Try(a[i - 1] - 1);
        Try(a[i - 1]);
      }
      ans = min(ans, curr - prv);
    }
    ans += Get(2, n - 1);
    cout << ans << "\n";
  }

  int Get(int l, int r) {
    l = max(2, l);
    r = min(n - 1, r);
    int ans = 0;
    for (int i = l; i <= r; ++i) {
      ans += (a[i - 1] < a[i] && a[i] > a[i + 1]);
      ans += (a[i - 1] > a[i] && a[i] < a[i + 1]);
    }
    return ans;
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
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}