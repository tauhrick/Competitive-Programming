#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

namespace sieve {
  vector<int> primes;
  vector<bool> is_prime;
  vector<int> min_fact;

  void RunSieve(int max_n) {
    max_n = max(max_n, 1);
    min_fact.resize(max_n + 1);
    is_prime.assign(max_n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= max_n; ++i) {
      if (is_prime[i]) {
        primes.push_back(i);
        min_fact[i] = i;
        for (int64_t j = int64_t(i) * i; j <= max_n; j += i) {
          if (is_prime[j]) {
            is_prime[j] = false;
            min_fact[j] = i;
          }
        }
      }
    }
  }
} // namespace sieve

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int64_t a, b; 
  int len;
  vector<vector<int64_t>> dp;

  void Read() {
    cin >> a >> b;
  }
 
  void Solve() {
    len = int(b - a);
    sieve::RunSieve(len);
    dp = vector(len + 1, vector(1 << sieve::primes.size(), int64_t(-1)));
    cout << Get(0, 0) << '\n';
  }

  int64_t Get(int ind, int mask) {
    if (ind == len + 1) {
      return 1;
    }
    auto &ans = dp[ind][mask];
    if (ans == -1) {
      ans = Get(ind + 1, mask);
      bool can_add = true;
      int new_mask = 0;
      for (int i = 0; i < int(sieve::primes.size()); ++i) {
        if ((a + ind) % sieve::primes[i] == 0) {
          new_mask |= (1 << i);
          if ((mask >> i) & 1) {
            can_add = false;
          }
        }
      }
      if (can_add) {
        ans += Get(ind + 1, mask | new_mask);
      }
    }
    return ans;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}