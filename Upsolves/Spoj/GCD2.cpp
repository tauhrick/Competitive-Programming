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
  int a;
  string b;

  void Read() {
    cin >> a >> b;
  }
 
  void Solve() {
    if (a == 0) {
      cout << b << '\n';
      return;
    }
    int b_mod_a = 0;
    for (int i = int(b.size()) - 1, coeff = 1; i >= 0; --i) {
      int dig = b[i] - '0';
      b_mod_a = (b_mod_a + coeff * dig) % a;
      coeff = (coeff * 10) % a;
    }
    cout << __gcd(a, b_mod_a) << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}