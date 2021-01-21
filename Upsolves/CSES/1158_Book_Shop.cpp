#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif
 
const int kLowInf = INT_MIN;
 
class Task {
 private:
  int n, x;
  vector<int> h;
  vector<int> s;
 
  void Read() {
    cin >> n >> x;
    h.resize(n);
    for (auto &i : h) {
      cin >> i;
    }
    s.resize(n);
    for (auto &i : s) {
      cin >> i;
    }
  }
 
  void Solve() {
    auto max_books = vector(n, vector(x + 1, 0));
    for (int j = 0; j < n; ++j) {
      for (int i = 1; i <= x; ++i) {
        if (j - 1 >= 0) {
          max_books[j][i] = max(max_books[j][i], max_books[j - 1][i]);
        }
        if (i - h[j] >= 0) {
          max_books[j][i] = max(max_books[j][i], s[j] + (j - 1 >= 0 ? max_books[j - 1][i - h[j]] : 0));
        }
      }
    }
    cout << max_books[n - 1][x] << "\n";
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