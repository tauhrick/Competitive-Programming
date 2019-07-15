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

struct Dsu {
  vector<int> par, sz;

  Dsu(int n) {
    par.resize(n + 1);
    iota(par.begin(), par.end(), 0);
    sz.resize(n + 1, 1);
  }

  int find(int x) {
    return (x == par[x] ? x : par[x] = find(par[x]));
  }

  void merge(int a, int b) {
    a = find(a); 
    b = find(b);
    if (sz[a] < sz[b]) {
      swap(a, b);
    }
    sz[a] += sz[b];
    par[b] = a;
  }

  bool same(int a, int b) {
    return find(a) == find(b);
  }
};

using Mint = Modular<998244353>;

const int N = 2000;

void test_case() {
  int n, m;
  cin >> n >> m;
  map<pair<int, int>, int> edges;
  for (int i = 1; i <= m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    int u = min(x, y);
    int v = max(x, y);
    if (!edges.count({u, v})) {
      edges[{u, v}] = w;
    } else {
      edges[{u, v}] = min(edges[{u, v}], w);
    }
  }
  vector<vector<pair<int, int>>> G1(n + 1);
  vector<pair<int, pair<int, int>>> info;
  for (auto e : edges) {
    G1[e.first.first].emplace_back(e.first.second, e.second);
    G1[e.first.second].emplace_back(e.first.first, e.second);
    info.push_back({e.second, e.first});
  }
  edges.clear();
  for (int i = 1; i <= m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    int u = min(x, y);
    int v = max(x, y);
    if (!edges.count({u, v})) {
      edges[{u, v}] = w;
    } else {
      edges[{u, v}] = min(edges[{u, v}], w);
    }
  }
  vector<vector<pair<int, int>>> G2(n + 1);
  for (auto e : edges) {
    G2[e.first.first].emplace_back(e.first.second, e.second);
    G2[e.first.second].emplace_back(e.first.first, e.second);
  }
  Mint ans = 0;
  if (n <= N) {
    vector<vector<int>> mn1(n + 1, vector<int>(n + 1)), mn2(n + 1, vector<int>(n + 1));
    auto dijkstra = [&](auto src, auto& G, auto& mn) {
      vector<bool> seen(n + 1);
      int a = src;
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      pq.push({-INT_MAX, src});
      while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (seen[p.second]) {
          continue;
        }
        mn[a][p.second] = p.first;
        seen[p.second] = true;
        for (auto v : G[p.second]) {
          if (!seen[v.first]) {
            pq.push({max(p.first, v.second), v.first});
          }
        }
      }
    };
    for (int i = 1; i <= n; ++i) {
      dijkstra(i, G1, mn1);
      dijkstra(i, G2, mn2);
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        ans += Mint(mn1[i][j]) * Mint(mn2[i][j]);
      }
    }
  } else {
    sort(info.begin(), info.end());
    Dsu network(n);
    for (auto e : info) {
      //~ {cost, {u, v}}
      int cost = e.first;
      int u = e.second.first;
      int v = e.second.second;
      int p_u = network.find(u);
      int p_v = network.find(v);
      if (p_u != p_v) {
        Mint to_add(1LL * cost * cost);
        to_add *= 1LL * network.sz[p_u] * network.sz[p_v];
        ans += to_add;
        network.merge(u, v);
      }
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
