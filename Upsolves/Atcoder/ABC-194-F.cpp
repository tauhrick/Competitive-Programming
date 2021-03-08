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

const int kD = 16;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  using Mint = Modular<int(1e9) + 7>;

  string n;
  int k;
  vector<vector<Mint>> dp;
  vector<vector<int>> seen;

  void Read() {
    cin >> n >> k;
  }
 
  void Solve() {
    Mint ans = IsValidAlready();
    dp = vector(n.size(), vector(k + 1, Mint(0)));
    seen = vector(n.size(), vector(k + 1, 0));
    set<int> done_digits;
    for (int less_pos = 0; less_pos < int(n.size()); ++less_pos) {
      int dig = HexToInt(n[less_pos]);
      for (int curr = (less_pos == 0 ? 1 : 0); curr < dig; ++curr) {
        ans += Get(less_pos + 1, int(done_digits.size()) + !done_digits.count(curr));
      }
      done_digits.insert(dig);
    }
    for (int st = 1; st < int(n.size()); ++st) {
      ans += Mint(15) * Get(st + 1, 1);
    }
    cout << ans.get() << '\n';
  }

  bool IsValidAlready() {
    set unq(n.begin(), n.end());
    return int(unq.size()) == k;
  }

  int HexToInt(char ch) {
    if ('0' <= ch && ch <= '9') {
      return int(ch - '0');
    } else {
      return 10 + int(ch - 'A');
    }
  }

  Mint Get(int ind, int done) {
    if (done > k) {
      return Mint(0);
    } else if (ind == int(n.size())) {
      return Mint(done == k);
    }
    auto &ans = dp[ind][done];
    auto &vis = seen[ind][done];
    if (!vis) {
      vis = true;
      ans = Mint(done) * Get(ind + 1, done) + Mint(16 - done) * Get(ind + 1, done + 1);
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
