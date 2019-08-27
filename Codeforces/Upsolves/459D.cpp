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

template <typename T>
class Fenwick {
public:
  vector<T> Fenw;
  int n;

  Fenwick(int _n) : n(_n) {
    Fenw.resize(n);
  }

  void modify(int x, T v) {
    while (x < n) {
      Fenw[x] += v;
      x |= (x + 1);
    }
  }

  T get(int x) {
    T v{};
    while (x >= 0) {
      v += Fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return v;
  }
};

const int N = 1e6 + 10;

void test_case() {
  int n;
  cin >> n;
  vector<int> A(n + 1);
  map<int, int> cnt_r;
  Fenwick<int> fenw(N);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    ++cnt_r[A[i]];
    fenw.modify(cnt_r[A[i]], 1);
  }
  map<int, int> cnt_l;
  long long res = 0;
  for (int i = 1; i <= n; ++i) {
    fenw.modify(cnt_r[A[i]], -1);
    --cnt_r[A[i]];
    ++cnt_l[A[i]];
    res += fenw.get(cnt_l[A[i]] - 1) - fenw.get(0);
  }
  cout << res << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
