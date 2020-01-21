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

using Mint = Modular<987654319>;

const int N = 3e3 + 10;

int n;
int A[N];
Mint c_g[N][N];
Mint e_l[N][N];
Mint b_c[N][N];
Mint f_e[N][N];
Mint ans;

void pre() {
  for (int c = 1; c <= n; ++c) {
    for (int a = c - 1; a >= 1; --a) {
      c_g[c][a] += c_g[c][a + 1];
      c_g[c][a] += A[a] > A[c];
    }
  }
  for (int e = n; e >= 1; --e) {
    for (int g = e + 1; g <= n; ++g) {
      e_l[e][g] += e_l[e][g - 1];
      e_l[e][g] += A[g] < A[e];
    }
  }
  for (int c = 1; c <= n; ++c) {
    for (int b = c - 1; b >= 1; --b) {
      if (A[b] < A[c]) {
        b_c[b][c] = c_g[c][1] - c_g[c][b];
      }
    }
  }
  for (int b = 1; b <= n; ++b) {
    for (int c = 1; c <= n; ++c) {
      b_c[b][c] += b_c[b][c - 1];
    }
  }
  for (int e = n; e >= 1; --e) {
    for (int f = e + 1; f <= n; ++f) {
      if (A[f] > A[e]) {
        f_e[f][e] = e_l[e][n] - e_l[e][f];
      }
    }
  }
  for (int f = 1; f <= n; ++f) {
    for (int e = 1; e <= n; ++e) {
      f_e[f][e] += f_e[f][e - 1];
    }
  }
  for (int d = 1; d <= n; ++d) {
    Mint pref;
    for (int b = d - 1; b >= 1; --b) {
      if (A[d] < A[b]) {
        pref += b_c[b][d - 1] - b_c[b][b - 1];
      }
    }
    Mint suff;
    for (int f = d + 1; f <= n; ++f) {
      if (A[f] < A[d]) {
        suff += f_e[f][f] - f_e[f][d];
      }
    }
    ans += pref * suff;
  }
}

void test_case() {
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
  }
  pre();
  cout << ans.get() << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
