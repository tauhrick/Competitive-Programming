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

const int kN = int(2e5);

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  using Mint = Modular<int(1e9) + 7>;

  int n, q;
  vector<int> a;
  vector<int> min_fact;
  map<int, int> prime_hash;
  vector<map<int, int>> cnt;
  Mint res;

  void Read() {
    cin >> n >> q;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }

  void Pre() {
    min_fact = vector(kN + 1, INT_MAX);
    for (int i = 2; i <= kN; ++i) {
      if (min_fact[i] == INT_MAX) {
        prime_hash[i] = int(prime_hash.size());
        for (int j = i; j <= kN; j += i) {
          min_fact[j] = min(min_fact[j], i);
        }
      }
    }
  }
 
  void Solve() {
    Pre();
    res = Mint(1);
    cnt.resize(prime_hash.size());
    for (int i = 0; i < n; ++i) {
      Query(i, a[i]);
    }
    while (q--) {
      int ind, x;
      cin >> ind >> x;
      --ind;
      Query(ind, x);
      cout << res.get() << '\n';
    }
  }

  void Query(int ind, int x) {
    while (x != 1) {
      int f = min_fact[x];
      int f_ind = prime_hash[f];
      ++cnt[f_ind][ind];
      if (int(cnt[f_ind].size()) == n) {
        int min_cnt = INT_MAX;
        for (auto &i : cnt[f_ind]) {
          min_cnt = min(min_cnt, i.second);
        }
        res *= Mint(f).pow(min_cnt);
        for (int i = 0; i < n; ++i) {
          cnt[f_ind][i] -= min_cnt;
          if (cnt[f_ind][i] == 0) {
            cnt[f_ind].erase(i);
          }
        }
      }
      x /= f;
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}