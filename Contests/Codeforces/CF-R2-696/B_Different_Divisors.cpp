#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kN = int(1e6);

vector<int> primes;

void Pre() {
  auto is_prime = vector(kN + 1, true);
  for (int i = 2; i <= kN; ++i) {
    if (is_prime[i]) {
      primes.emplace_back(i);
      for (int j = 2 * i; j <= kN; j += i) {
        is_prime[j] = false;
      }
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
  int d;
  
  void Read() {
    cin >> d;
  }
 
  void Solve() {
    int prv = 1;
    int64_t ans = 1;
    for (int i = 1; i <= 2; ++i) {
      int ind = int(lower_bound(primes.begin(), primes.end(), prv + d) - primes.begin());
      assert(ind < int(primes.size()));
      ans *= primes[ind];
      prv = primes[ind];
    }
    cout << ans << "\n";
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Pre();
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}