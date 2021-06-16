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

using Mint = Modular<int(1.0e9) + 7>;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n, m;
  vector<vector<Mint>> dp;
  vector<vector<int>> seen;

  void Read() {
    cin >> n >> m;    
  }

  void Solve() {
    dp = vector(n + 1, vector(32, Mint(0)));
    seen = vector(n + 1, vector(32, 0));
    Mint res(1);
    for (int i = 2; int64_t(i) * i <= m; ++i) {
      if (m % i == 0) {
        int cnt = 0;
        while (m % i == 0) {
          ++cnt;
          m /= i;
        }
        res *= Get(1, cnt);
      }
    }
    if (m != 1) {
      res *= Get(1, 1);
    }
    cout << res.get() << '\n';
  }

  Mint Get(int nn, int rr) {
    if (nn == n) {
      return Mint(1);
    }
    auto &ans = dp[nn][rr];
    auto &vis = seen[nn][rr];
    if (!vis) {
      vis = true;
      ans = Get(nn + 1, rr) + (rr >= 1 ? Get(nn, rr - 1) : Mint(0));
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