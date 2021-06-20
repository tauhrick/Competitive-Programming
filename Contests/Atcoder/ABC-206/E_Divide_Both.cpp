#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kN = int(1.0e6);

vector<vector<int>> factors;
vector<int> mobius;

void Pre() {
  factors.resize(kN + 1);
  vector<bool> is_prime(kN + 1, true);
  vector<int> prime_factors_count(kN + 1);
  is_prime[0] = is_prime[1] = false;
  mobius.assign(kN + 1, -1);
  for (int i = 1; i <= kN; ++i) {
    if (is_prime[i]) {
      int64_t sq_i = int64_t(i) * i;
      for (int j = i; j <= kN; j += i) {
        is_prime[j] = false;
        if (j % sq_i != 0) {
          ++prime_factors_count[j];
        } else {
          mobius[j] = 0;
        }
      }
    }
    for (int j = i; j <= kN; j += i) {
      factors[j].push_back(i);
    }
  }
  for (int i = 1; i <= kN; ++i) {
    if (mobius[i] == 0) {
      continue;
    }
    mobius[i] = prime_factors_count[i] % 2 == 1 ? -1 : 1;
  }
}

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int l, r;

  void Read() {
    cin >> l >> r; 
  }
 
  void Solve() {
    l = max(2, l);
    int n = r - l + 1;
    int64_t res = int64_t(n) * n;
    for (int i = l; i <= r; ++i) {
      int good_factors = int(factors[i].end() - lower_bound(factors[i].begin(), factors[i].end(), l));
      int co_prime = 0;
      for (auto &f : factors[i]) {
        co_prime += mobius[f] * (r / f - (l + f - 1) / f + 1);
      }
      res -= co_prime + 2 * (good_factors - 1) + 1;
    }
    cout << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Pre();
  Task t;
  t.Perform();
  return 0;
}