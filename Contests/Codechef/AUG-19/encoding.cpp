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

const int N = 1e5 + 10;

Mint power[N];
Mint dp1[N][11];
bool seen1[N][11];
Mint dp2[N][11][2];
bool seen2[N][11][2];

Mint take_all(int tot, int pos = 0, int prv = 10) {
  if (pos == tot) {
    if (prv == 10) {
      return Mint(0);
    } else {
      return Mint(prv) * power[pos - 1];
    }
  }
  auto& ans = dp1[pos][prv];
  auto& vis = seen1[pos][prv];
  if (!vis) {
    vis = true;
    ans = 0;
    for (int curr = 0; curr <= 9; ++curr) {
      if (curr != prv && prv != 10) {
        ans += power[tot - pos - 1] * Mint(prv) * power[pos - 1] + take_all(tot, pos + 1, curr);
      } else {
        ans += take_all(tot, pos + 1, curr);
      }
    }
  }
  return ans;
}

Mint take_less(vector<Mint>& dp3, string& up, int pos = 0, int prv = 10, bool less = false) {
  if (pos == (int) up.size()) {
    return Mint(0);
  }
  auto& ans = dp2[pos][prv][less];
  auto& vis = seen2[pos][prv][less];
  if (!vis) {
    vis = true;
    ans = 0;
    int st = (pos == 0 ? 1 : 0);
    int en = (less ? 9 : up[pos] - '0');
    for (int curr = st; curr <= en; ++curr) {
      bool nxt = (curr == en ? less : true);
      if (curr != prv) {
        ans += (nxt ? power[(int) up.size() - pos - 1] : dp3[pos + 1]) * Mint(curr) * power[(int) up.size() - pos - 1];
      }
      ans += take_less(dp3, up, pos + 1, curr, nxt);
    }
  }
  return ans;
}

Mint take_less(string& up) {
  vector<Mint> dp3(up.size() + 1);
  dp3.back() = Mint(1);
  for (int i = up.size() - 1, nxt = 0; i >= 0; --i, ++nxt) {
    dp3[i] += dp3[i + 1];
    Mint curr = Mint(up[i] - '0');
    if (i == 0) {
      curr -= Mint(1);
    }
    dp3[i] += curr * power[nxt];
  }
  return take_less(dp3, up);
}

void test_case() {
  int n_l, n_r;
  string l, r;
  cin >> n_l >> l >> n_r >> r;
  Mint res;
  memset(seen1, false, sizeof seen1);
  res += take_all(n_r - 1);
  memset(seen1, false, sizeof seen1);
  res -= take_all(n_l - 1);
  memset(seen2, false, sizeof seen2);
  res += take_less(r);
  memset(seen2, false, sizeof seen2);
  res -= take_less(l);
  for (int i = 0, p = (int) l.size() - 1; i < (int) l.size(); ) {
    res += Mint(l[i] - '0') * power[p];
    int st = i;
    while (i < (int) l.size() && l[i] == l[st]) {
      ++i;
      --p;
    }
  }
  cout << res.get() << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  power[0] = 1;
  for (int i = 1; i < N; ++i) {
    power[i] = power[i - 1] * 10;
  }
  int tc;
  cin >> tc;
  while (tc--) {
    test_case();
  }
  return 0;
}
