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

using Mint = Modular<int(1e9 + 7)>;

void test_case() {
  string s;
  cin >> s;
  int n = s.size();
  for (auto ch : s) {
    if (ch == 'm'|| ch == 'w') {
      cout << "0\n";
      return;
    }
  }
  vector<Mint> dp(n + 1);
  vector<int> seen(n + 1);
  function<Mint(int)> solve = [&](int len) {
    if (len <= 1) {
      return Mint(1);
    }
    auto& ans = dp[len];
    auto& vis = seen[len];
    if (!vis) {
      vis = true;
      ans += solve(len - 2);
      ans += solve(len - 1);
    }
    return ans;
  };
  Mint ans = 1;
  for (int i = 0; i < n; ) {
    if (s[i] == 'u' || s[i] == 'n') {
      int _i = i;
      while (i < n && s[i] == s[_i]) {
        ++i;
      }
      ans *= solve(i - _i);
    } else {
      ++i;
    }
  }
  cout << ans.get() << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
