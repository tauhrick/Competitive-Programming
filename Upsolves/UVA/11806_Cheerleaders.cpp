#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

template <uint32_t mod>
class Modular {
private:
  uint32_t n;

public:
  Modular(int64_t _n = 0) : n(uint32_t((_n >= 0 ? _n : mod - (-_n) % mod) % mod)) {}

  uint32_t get() const { return n; }
  bool operator==(const Modular &o) const { return n == o.n; }
  bool operator!=(const Modular &o) const { return n != o.n; }
  Modular& operator/=(const Modular &o) { return (*this) *= o.inv(); }
  Modular operator+(const Modular &o) const { return Modular(*this) += o; }
  Modular operator-(const Modular &o) const { return Modular(*this) -= o; }
  Modular operator*(const Modular &o) const { return Modular(*this) *= o; }
  Modular operator/(const Modular &o) const { return Modular(*this) /= o; }
  friend string to_string(const Modular &m) { return to_string(m.get()); }

  Modular& operator+=(const Modular &o) {
    n += o.n;
    n = (n < mod ? n : n - mod);
    return *this; 
  }

  Modular& operator-=(const Modular &o) {
    n += mod - o.n;
    n = (n < mod ? n : n - mod);
    return *this;
  }

  Modular& operator*=(const Modular &o) {
    n = uint32_t(uint64_t(n) * o.n % mod);
    return *this;
  }

  Modular pow(uint64_t b) const {
    Modular ans(1), m = Modular(*this);
    while (b) {
      if (b & 1) {
        ans *= m;
      }
      m *= m;
      b >>= 1;
    }
    return ans;
  }

  Modular inv() const {
    int32_t a = n, b = mod, u = 0, v = 1;
    while (a) {
      int32_t t = b / a;
      b -= t * a;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    assert(b == 1);
    return Modular(u);
  }
};

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  using Mint = Modular<int(1.0e6) + 7>;

  int m, n, k; 
  vector<vector<Mint>> dp;

  void Read() {
    cin >> m >> n >> k; 
  }
 
  void Solve() {
    Pre();
    Mint total = Get(n * m, k);
    Mint bad_1 = Mint(2) * (Get((m - 1) * n, k) + Get((n - 1) * m, k));
    Mint bad_2 = Get((m - 2) * n, k) + Get((n - 2) * m, k) + Mint(4) * Get((m - 1) * (n - 1), k);
    Mint bad_3 = Mint(2) * (Get((n - 2) * (m - 1), k) + Get((m - 2) * (n - 1), k));
    Mint bad_4 = Get((m - 2) * (n - 2), k);
    cout << (total - bad_1 + bad_2 - bad_3 + bad_4).get() << '\n';
  }

  void Pre() {
    int cells = n * m;
    dp.assign(cells + 1, vector<Mint>(cells + 1, Mint(0)));
    dp[0][0] = 1;
    for (int i = 1; i <= cells; ++i) {
      dp[i][0] = dp[i][i] = 1;
      for (int j = 1; j < i; ++j) {
        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
      }
    }
  }

  Mint Get(int nn, int rr) {
    if (rr > nn) {
      return Mint(0);
    } else {
      return dp[nn][rr];
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    cout << "Case " << tt << ": ";
    Task t;
    t.Perform();
  }
  return 0;
}