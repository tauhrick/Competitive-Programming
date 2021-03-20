#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

namespace sieve {

vector<int> min_fact;
vector<int> primes;
vector<bool> is_prime;

void RunSieve(int en) {
  en = max(en, 1);
  min_fact.resize(en + 1);
  is_prime.assign(en + 1, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= en; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      min_fact[i] = i;
      for (int64_t j = int64_t(i) * i; j <= en; j += i) {
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
  int c, d, x; 

  void Read() {
    cin >> c >> d >> x;
  }
 
  void Solve() {
    int64_t res = 0;
    for (int i = 1; int64_t(i) * i <= x; ++i) {
      if (x % i == 0) {
        res += Count(i);
        if (x / i != i) {
          res += Count(x / i);
        }
      }
    }
    cout << res << '\n';
  }

  int Count(int g) {
    int f = x / g;
    if ((d + f) % c != 0) return 0;
    int y = (d + f) / c;
    int prime_factors = 0;
    while (y != 1) {
      int p = sieve::min_fact[y];
      ++prime_factors;
      while (y % p == 0) {
        y /= p;
      }
    }
    return 1 << prime_factors;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  sieve::RunSieve(int(2e7));
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}