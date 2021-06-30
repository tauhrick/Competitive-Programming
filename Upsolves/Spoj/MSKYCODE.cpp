#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kId = int(1.0e4);
vector<int> mobius;

void Precompute() {
  mobius.assign(kId + 1, -1);
  vector<int> is_prime(kId + 1, true);
  vector<int> unq_prime_factors(kId + 1, 0);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= kId; ++i) {
    if (is_prime[i]) {
      for (int j = i; j <= kId; j += i) {
        is_prime[j] = false;
        if (j % (int64_t(i) * i) == 0) {
          mobius[j] = 0;
        } else {
          ++unq_prime_factors[j];
        }
      }
    }
  }
  for (int i = 0; i <= kId; ++i) {
    if (mobius[i] == -1) {
      mobius[i] = (unq_prime_factors[i] % 2 == 0 ? 1 : -1);
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
  int n;
  vector<int> ids;  
  vector<int> multiples;

  void Read() {
    if (!(cin >> n)) {
      exit(0);
    }
    ids.resize(n);
    for (auto &i : ids) {
      cin >> i;
    }
  }
 
  void Solve() {
    multiples.resize(kId + 1);
    for (auto id : ids) {
      for (int i = 1; i * i <= id; ++i) {
        if (id % i == 0) {
          ++multiples[i];
          if (i != id / i) {
            ++multiples[id / i];
          }
        }
      }
    }
    int64_t res = Choose4(n);
    for (int d = 2; d <= kId; ++d) {
      if (mobius[d] != 0) {
        res += mobius[d] * Choose4(multiples[d]);
      }
    }
    cout << res << '\n';
  }

  int64_t Choose4(int nn) {
    if (nn < 4) {
      return 0;
    } else {
      return (int64_t(nn) * (nn - 1) * (nn - 2) * (nn - 3)) / 24;
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Precompute();
  while (true) {
    Task t;
    t.Perform();
  }
  return 0;
}