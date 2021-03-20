#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

template <uint32_t mod>
class Modular {
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

 private:
  uint32_t n;
};

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  using Mint = Modular<998244353>;

  string x, y;  

  void Read() {
    cin >> x >> y; 
  }
 
  int len_x, len_y;
  vector<vector<vector<Mint>>> dp;
  vector<vector<vector<int>>> seen;

  void Solve() {
    len_x = int(x.size()), len_y = int(y.size());
    dp = vector(len_x + 1, vector(len_y + 1, vector(5, Mint(0))));
    seen = vector(len_x + 1, vector(len_y + 1, vector(5, 0)));
    Mint res;
    for (int st_x = 0; st_x < len_x; ++st_x) {
      for (int st_y = 0; st_y < len_y; ++st_y) {
        res += Get(st_x, st_y, 0);
      }
    }
    cout << res.get() << '\n';
  }

  Mint Get(int ind_x, int ind_y, int last_taken) {
    if (make_pair(ind_x, ind_y) == make_pair(len_x, len_y)) return Mint(0);
    auto &ans = dp[ind_x][ind_y][last_taken];
    auto &vis = seen[ind_x][ind_y][last_taken];
    if (!vis) {
      vis = true;
      if (last_taken == 0) {
        ans += Get(ind_x + 1, ind_y, 1);
        ans += Get(ind_x, ind_y + 1, 2);
      } else {
        char prv = (last_taken == 1 || last_taken == 3 ? x[ind_x - 1] : y[ind_y - 1]);
        if (last_taken == 1) {
          if (ind_x < len_x && x[ind_x] != prv) ans += Get(ind_x + 1, ind_y, 1);
          if (ind_y < len_y && y[ind_y] != prv) ans += Mint(1) + Get(ind_x, ind_y + 1, 4);
        } else if (last_taken == 2) {
          if (ind_x < len_x && x[ind_x] != prv) ans += Mint(1) + Get(ind_x + 1, ind_y, 3);
          if (ind_y < len_y && y[ind_y] != prv) ans += Get(ind_x, ind_y + 1, 2);
        } else {
          if (ind_x < len_x && x[ind_x] != prv) ans += Mint(1) + Get(ind_x + 1, ind_y, 3);
          if (ind_y < len_y && y[ind_y] != prv) ans += Mint(1) + Get(ind_x, ind_y + 1, 4);
        }
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