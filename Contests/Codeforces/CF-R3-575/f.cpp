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

void test_case() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<tuple<int, int, int>> edges(m);
  for (auto& [w, u, v] : edges) {
    cin >> u >> v >> w;
  }
  sort(edges.begin(), edges.end());
  int sz = 2 * k;
  vector<set<pair<int, int>>> G(sz);
  map<int, int> ind;
  auto get_ind = [&](int foo) {
    if (!ind.count(foo)) {
      ind[foo] = ind.size();
    }
    return ind[foo];
  };
  for (int i = 0; i < min(m, k); ++i) {
    auto [w, u, v] = edges[i];
    int x = get_ind(u);
    int y = get_ind(v);
    G[x].insert({y, w});
    G[y].insert({x, w});
  }
  assert((int) ind.size() <= sz);
  vector<long long> paths;
  for (int i = 0; i < sz; ++i) {
    vector<long long> dist(sz, LLONG_MAX);
    vector<bool> seen(sz);
    priority_queue<pair<long long, int>> pq;
    pq.push({0, i});
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      d = -d;
      pq.pop();
      if (seen[u]) {
        continue;
      }
      seen[u] = true;
      dist[u] = d;
      for (auto [v, w] : G[u]) {
        if (!seen[v] && d + w < dist[v]) {
          pq.push({-(d + w), v});
        }
      }
    }
    for (int j = i + 1; j < sz; ++j) {
      if (dist[j] != LLONG_MAX) {
        paths.emplace_back(dist[j]);
      }
    }
  }
  sort(paths.begin(), paths.end());
  assert((int) paths.size() >= k);
  cout << paths[k - 1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
