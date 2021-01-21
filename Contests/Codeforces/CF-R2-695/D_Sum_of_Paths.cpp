#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
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

struct Query {
  int idx, x;
};

class Task {
 private:
  using Mint = Modular<int(1e9) + 7>;

  int n, k, q;
  vector<int> a;
  vector<Query> queries;
  vector<vector<Mint>> dp;
  vector<vector<int>> seen;
  vector<Mint> contri;

  void Read() {
    cin >> n >> k >> q;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    queries.resize(q);
    for (auto &qq : queries) {
      cin >> qq.idx >> qq.x;
    }
  }
 
  void Solve() {
    ++k;
    dp = vector(n + 1, vector(k + 1, Mint(0)));
    seen = vector(n + 1, vector(k + 1, 0));
    contri.resize(n + 1);
    Mint ans;
    for (int pos = 1; pos <= n; ++pos) {
      for (int ind = 1; ind <= k; ++ind) {
        contri[pos] += Get(pos, k - ind) * Get(pos, ind - 1);
      }
      ans += contri[pos] * Mint(a[pos]);
    }
    for (auto &qq : queries) {
      ans -= contri[qq.idx] * Mint(a[qq.idx]);
      a[qq.idx] = qq.x;
      ans += contri[qq.idx] * Mint(a[qq.idx]);
      cout << ans.get() << "\n";
    }
  }

  Mint Get(int ind, int left) {
    if (left == 0) {
      return Mint(1);
    }
    auto &ans = dp[ind][left];
    auto &vis = seen[ind][left];
    if (!vis) {
      vis = true;
      if (ind - 1 >= 1) {
        ans += Get(ind - 1, left - 1);
      }
      if (ind + 1 <= n) {
        ans += Get(ind + 1, left - 1);
      }
    }
    return ans;
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Task t;
  t.Perform();
  return 0;
}