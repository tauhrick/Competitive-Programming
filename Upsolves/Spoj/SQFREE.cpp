#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kF = int(1.0e7);

vector<int64_t> factors;
vector<int> cnt_factors;

void Pre() {
  vector<int> cnt(kF + 1, 0);
  vector<bool> is_prime(kF + 1, true);
  vector<bool> is_bad(kF + 1, false);
  for (int i = 2; i <= kF; ++i) {
    int64_t sq_i = int64_t(i) * i;
    if (is_prime[i]) {
      cnt[i] = 1;
      for (int j = 2 * i; j <= kF; j += i) {
        if (j % sq_i == 0) {
          is_bad[j] = true;
        }
        is_prime[j] = false;
        ++cnt[j];
      }
    }
    if (!is_bad[i]) {
      factors.push_back(sq_i);
      cnt_factors.push_back(cnt[i]);
    }
  }
}

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int64_t n; 

  void Read() {
    cin >> n; 
  }
 
  void Solve() {
    int64_t res = n;
    for (int i = 0; i < int(factors.size()) && factors[i] <= n; ++i) {
      res += (cnt_factors[i] % 2 == 1 ? -1 : 1) * (n / factors[i]);
    }
    cout << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Pre();
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}