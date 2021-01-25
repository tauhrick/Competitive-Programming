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
  using Mint = Modular<int(1e9) + 7>;

  int n;
  vector<int> a;
  vector<int> nxt;
  vector<Mint> dp;
  vector<int> seen;

  void Read() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
  }
 
  void Solve() {
    int mx_val = GetMex();
    vector<int> pos(n + 1, -1);
    set<int> st;
    nxt.assign(n + 1, -1);
    for (int i = n; i >= 1; --i) {
      if (i + 1 <= n) {
        nxt[i] = nxt[i + 1];
      }
      if (a[i] <= mx_val) {
        if (pos[a[i]] != -1) {
          st.erase(pos[a[i]]);
        }
        pos[a[i]] = i;
        st.insert(pos[a[i]]);
      }
      if (int(st.size()) == mx_val) {
        if (mx_val != 0) {
          nxt[i] = *st.rbegin();
        } else {
          nxt[i] = i;
        }
      }
    }
    dp = vector(n + 1, Mint(0));
    seen = vector(n + 1, 0);
    cout << Get(1).get() << "\n";
  }

  int GetMex() {
    vector<int> cnt(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      ++cnt[a[i]];
    }
    for (int i = 0; i <= n; ++i) {
      if (cnt[i] == 0) return i;
    }
    return -1;
  }

  Mint Get(int ind) {
    if (ind == n + 1) return Mint(1);
    auto &ans = dp[ind];
    auto &vis = seen[ind];
    if (!vis) {
      vis = true;
      if (ind != 1) {
        ans += Get(ind + 1);
      }
      if (nxt[ind] != -1) {
        ans += Get(nxt[ind] + 1);
      }
    }
    return ans;
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}