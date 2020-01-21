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

const int LG = 63;

void test_case() {
  int n;
  cin >> n;
  vector<long long> A(n + 1);
  vector<vector<int>> pos(LG);
  for (int i = 1; i <= n; ++i) {
    cin >> A[i];
    for (int bit = 0; bit < LG; ++bit) {
      if (A[i] & (1LL << bit)) {
        pos[bit].emplace_back(i);
      }
    }
  }
  vector<set<int>> G(n + 1);
  set<pair<int, int>> edges;
  for (int i = 0; i < LG; ++i) {
    int sz = pos[i].size();
    if (sz >= 3) {
      cout << "3\n";
      return;
    } else if (sz <= 1) {
      continue;
    } else {
      int a = min(pos[i][0], pos[i][1]);
      int b = max(pos[i][0], pos[i][1]);
      G[a].insert(b);
      G[b].insert(a);
      edges.insert({a, b});
    }
  }
  int res = INT_MAX;
  for (auto [u, v] : edges) {
    G[u].erase(v);
    G[v].erase(u);
    vector<bool> seen(n + 1);
    queue<pair<int, int>> q;
    q.push({u, 1});
    while (!q.empty()) {
      auto [x, d] = q.front();
      q.pop();
      if (seen[x]) {
        continue;
      }
      seen[x] = true;
      if (x == v) {
        res = min(res, d);
        break;
      }
      for (auto y : G[x]) {
        if (!seen[y]) {
          q.push({y, d + 1});
        }
      }
    }
    G[u].insert(v);
    G[v].insert(u);
  }
  if (res == INT_MAX) {
    cout << "-1\n";
  } else {
    cout << res << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
