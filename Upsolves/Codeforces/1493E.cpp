#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n;
  string l, r;

  void Read() {
    cin >> n >> l >> r;
  }
 
  void Solve() {
    if (l[0] == '0' && r[0] == '1') {
      cout << string(n, '1');
    } else {
      if (r[n - 1] == '1') {
        cout << r;
      } else {
        if (l == string(n - 1, '0') + string(1, '1') || OkGap()) {
          cout << r.substr(0, n - 1) << '1';
        } else {
          cout << r;
        }
      }
    }
    cout << '\n';
  }

  bool OkGap() {
    Increment(l);
    Increment(l);
    return int(l.size()) == n && l <= r;
  }

  void Increment(string &s) {
    int carry = 1;
    for (int i = n - 1; i >= 0; --i) {
      int bit = s[i] - '0';
      int sum = bit + carry;
      s[i] = char('0' + sum % 2);
      carry = sum / 2;
    }
    if (carry) {
      s = "1" + s;
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}