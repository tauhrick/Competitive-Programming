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

template <typename T>
struct Matrix {
  vector<vector<T>> arr;
  int rows, cols;

  Matrix(int n, int m) {
    rows = n;
    cols = m;
    arr.assign(n, vector<T>(m));
  }

  void make_identical() {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (i == j) {
          arr[i][j] = 1;
        } else {
          arr[i][j] = 0;
        }
      }
    }
  }

  Matrix operator +(const Matrix &o) {
    assert(rows == o.rows && cols == o.cols);
    Matrix res(rows, cols);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        res.arr[i][j] = arr[i][j] + o.arr[i][j];
      }
    }
    return res;
  }

  Matrix operator *(const Matrix &o) {
    assert(cols == o.rows);
    Matrix res(rows, o.cols);
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < o.cols; ++j) {
        for (int k = 0; k < cols; ++k) {
          res.arr[i][j] += arr[i][k] * o.arr[k][j];
        }
      }
    }
    return res;
  }

  Matrix power(long long p) {
    assert(rows == cols);
    Matrix o = (*this);
    Matrix res(rows, cols);
    res.make_identical();
    while (p) {
      if (p & 1) {
        res = res * o;
      }
      o = o * o;
      p >>= 1;
    }
    return res;
  }
};

using Mint = Modular<int(1e9 + 7)>;

void test_case() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> A(n);
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  Matrix<Mint> T(n, n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      long long x = A[i] ^ A[j];
      if (__builtin_popcountll(x) % 3 == 0) {
        T.arr[i][j] = 1;
      }
    }
  }
  Matrix<Mint> B(n, 1);
  for (int r = 0; r < n; ++r) {
    B.arr[r][0] = 1;
  }
  Matrix<Mint> R = T.power(k - 1) * B;
  Mint ans = 0;
  for (int r = 0; r < n; ++r) {
    ans += R.arr[r][0];
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
