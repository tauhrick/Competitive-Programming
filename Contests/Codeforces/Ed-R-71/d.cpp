#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

template <uint32_t mod>
class Modular {
private:
  uint32_t n;

public:
  Modular(int64_t _n = 0) : n((_n >= 0 ? _n : mod - (-_n) % mod) % mod) {}

  uint32_t get() const {
    return n;
  }

  bool operator ==(const Modular& o) const {
    return n == o.n;
  }

  bool operator !=(const Modular& o) const {
    return n != o.n;
  }

  Modular& operator +=(const Modular& o) {
    n += o.n;
    n = (n < mod ? n : n - mod);
    return *this; 
  }

  Modular& operator -=(const Modular& o) {
    n += mod - o.n;
    n = (n < mod ? n : n - mod);
    return *this;
  }

  Modular& operator *=(const Modular& o) {
    n = uint64_t(n) * o.n % mod;
    return *this;
  }

  Modular& operator /=(const Modular& o) {
    return (*this) *= o.inv();
  }

  Modular operator +(const Modular& o) const {
    return Modular(*this) += o;
  }

  Modular operator -(const Modular& o) const {
    return Modular(*this) -= o;
  }

  Modular operator *(const Modular& o) const {
    return Modular(*this) *= o;
  }

  Modular operator /(const Modular& o) const {
    return Modular(*this) /= o;
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

using Mint = Modular<998244353>;

void test_case() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
  }
  vector<Mint> fact(n + 1);
  fact[0] = fact[1] = Mint(1);
  for (int i = 2; i <= n; ++i) {
    fact[i] = fact[i - 1] * Mint(i);
  }
  Mint res = fact[n];
  { // Ded first
    sort(a.begin(), a.end(), [](auto x, auto y){
      return x.first < y.first;
    });
    Mint ded(1);
    for (int i = 0; i < n; ) {
      int st = i;
      while (i < n && a[i].first == a[st].first) {
        ++i;
      }
      ded *= fact[i - st];
    }
    res -= ded;
  }
  { // Ded second
    sort(a.begin(), a.end(), [](auto x, auto y){
      return x.second < y.second;
    });
    Mint ded(1);
    for (int i = 0; i < n; ) {
      int st = i;
      while (i < n && a[i].second == a[st].second) {
        ++i;
      }
      ded *= fact[i - st];
    }
    res -= ded;
  }
  { // Add both
    sort(a.begin(), a.end());
    bool ok = true;
    for (int i = 1; i < n; ++i) {
      if (a[i].first >= a[i - 1].first && a[i].second >= a[i - 1].second) {
        continue;
      }
      ok = false;
    }
    if (ok) {
      Mint ded(1);
      for (int i = 0; i < n; ) {
        int st = i;
        while (i < n && a[i] == a[st]) {
          ++i;
        }
        ded *= fact[i - st];
      }
      res += ded;
    }
  }
  cout << res.get() << "\n";
}

int main() {
  test_case();
  return 0;
}
