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

class Segment_tree {
public:
  struct Node {
    int mx;
    
    Node(int _mx = INT_MIN) : mx(_mx) {}

    void apply(int o) {
      mx = o;
    }
  };

  Node unite(const Node& a, const Node& b) {
    return Node(max(a.mx, b.mx));
  }

  void pull(int tv, int lc, int rc) {
    Tree[tv] = unite(Tree[lc], Tree[rc]);
  }

  void push(int tv, int lc, int tr) {
    //
  }

  int n;
  vector<Node> Tree;

  Segment_tree(int _n) : n(_n) {
    Tree.resize(4 * n + 4);
    build(1, 1, n);
  }

  template <typename M>
  Segment_tree(const vector<M>& V) {
    n = V.size() - 1;
    assert(n > 0);
    Tree.resize(4 * n + 4);
    build(1, 1, n, V);
  }

  void build(int tv, int tl, int tr) {
    if (tl == tr) {
      return;
    } else {
      int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
      build(lc, tl, tm);
      build(rc, tm + 1, tr);
      pull(tv, lc, rc);
    }
  }

  template <typename M>
  void build(int tv, int tl, int tr, const vector<M>& V) {
    if (tl == tr) {
      Tree[tv].apply(V[tl]);
    } else {
      int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
      build(lc, tl, tm, V);
      build(rc, tm + 1, tr, V);
      pull(tv, lc, rc);
    }
  }

  template <typename M>
  void modify(int tv, int tl, int tr, int ql, int qr, const M& v) {
    if (ql > qr) {
      return;
    }
    if (qr < tl || tr < ql) {
      return;
    } else if (ql <= tl && tr <= qr) {
      Tree[tv].apply(v);
    } else {
      int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
      push(tv, lc, rc);
      modify(lc, tl, tm, ql, qr, v);
      modify(rc, tm + 1, tr, ql, qr, v);
      pull(tv, lc, rc);
    }
  }

  Node get(int tv, int tl, int tr, int ql, int qr) {
    if (ql > qr) {
      return Node(INT_MIN);
    }
    if (qr < tl || tr < ql) {
      return Node(INT_MIN);
    } else if (ql <= tl && tr <= qr) {
      return Tree[tv];
    } else {
      int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
      push(tv, lc, rc);
      return unite(get(lc, tl, tm, ql, qr), get(rc, tm + 1, tr, ql, qr));
    }
  }

  template <typename M>
  void modify(int p, const M& v) {
    modify(1, 1, n, p, p, v);
  }

  template <typename M>
  void modify(int ql, int qr, const M& v) {
    modify(1, 1, n, ql, qr, v);
  }

  Node get(int p) {
    return get(1, 1, n, p, p);
  }

  Node get(int ql, int qr) {
    return get(1, 1, n, ql, qr);
  }
};

struct Chain {
  int head, sz;
  
  Chain() {
    head = sz = 0;
  }
};

struct Node {
  int chain_no, chain_pos, sub_sz, par, dep, tot_pos;
  
  Node() {
    chain_no = chain_pos = sub_sz = par = dep = tot_pos = 0;
  }
};

const int N = 1e4 + 10, LG = log2(N) + 2;

int n;
int curr_chain, ctr;
vector<Chain> chain_info(N);
vector<Node> node_info(N);
vector<set<pair<int, int>>> G(N);
vector<vector<int>> up(N, vector<int>(LG));
vector<int> order;
map<pair<int, int>, int> cost;

void clear_data() {
  for (int i = 1; i <= n; ++i) {
    G[i].clear();
  }
  for (int i = 1; i < N; ++i) {
    chain_info[i] = Chain();
    node_info[i] = Node();
  }
  order.clear();
  cost.clear();
}

void pre_sz(int u, int p, int d) {
  node_info[u].sub_sz = 1;
  node_info[u].par = p;
  node_info[u].dep = d;
  for (auto nxt : G[u]) {
    int v = nxt.first;
    if (v != p) {
      pre_sz(v, u, d + 1);
      node_info[u].sub_sz += node_info[v].sub_sz;
    }
  }
}

void add_to_chain(int u) {
  if (chain_info[curr_chain].sz == 0) {
    chain_info[curr_chain].head = u;
  }
  ++chain_info[curr_chain].sz;
  node_info[u].chain_no = curr_chain;
  node_info[u].chain_pos = chain_info[curr_chain].sz;
  order.emplace_back(u);
  node_info[u].tot_pos = ++ctr;
}

void decompose(int u, int p) {
  add_to_chain(u);
  int max_sz = -1, special_node = -1;
  for (auto nxt : G[u]) {
    int v = nxt.first;
    if (v != p) {
      if (node_info[v].sub_sz > max_sz) {
        max_sz = node_info[v].sub_sz;
        special_node = v;
      }
    }
  }
  if (special_node != -1) {
    decompose(special_node, u);
  }
  for (auto nxt : G[u]) {
    int v = nxt.first;
    if (v != p && v != special_node) {
      ++curr_chain;
      decompose(v, u);
    }
  }
}

void hld(int root) {
  curr_chain = 1;
  ctr = 0;
  order.emplace_back(0);
  pre_sz(root, 0, 0);
  decompose(root, 0);
  assert(ctr == n);
  for (int i = 1; i <= n; ++i) {
    up[i][0] = node_info[i].par;
  }
  for (int k = 1; k < LG; ++k) {
    for (int i = 1; i <= n; ++i) {
      up[i][k] = up[up[i][k - 1]][k - 1];
    }
  }
}

int lca(int u, int v) {
  if (node_info[u].dep < node_info[v].dep) {
    swap(u, v);
  }
  int diff = node_info[u].dep - node_info[v].dep;
  for (int i = 0; i < LG; ++i) {
    if (diff & (1 << i)) {
      diff -= (1 << i);
      u = up[u][i];
    }
  }
  assert(diff == 0);
  if (u == v) {
    return u;
  }
  for (int i = LG - 1; i >= 0; --i) {
    if (up[u][i] != up[v][i]) {
      u = up[u][i];
      v = up[v][i];
    }
  }
  return up[u][0];
}

void test_case() {
  cin >> n;
  vector<pair<pair<int, int>, int>> edges(n);
  for (int i = 1; i < n; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    int u = min(a, b);
    int v = max(a, b);
    G[u].insert({v, w});
    G[v].insert({u, w});
    edges[i] = {{u, v}, w};
    cost[{u, v}] = w;
  }
  hld(1);
  vector<int> weights = {INT_MIN};
  for (int i = 1; i + 1 < (int) order.size(); ++i) {
    int u = min(order[i], order[i + 1]), v = max(order[i], order[i + 1]);
    if (node_info[u].chain_no == node_info[v].chain_no) {
      weights.emplace_back(cost[{u, v}]);
    } else {
      weights.emplace_back(INT_MIN);
    }
  }
  Segment_tree sg(weights);
  string quer;
  auto get = [&](int a, int lca_node) {
    int res = INT_MIN;
    while (true) {
      if (node_info[a].chain_no == node_info[lca_node].chain_no) {
        res = max(res, sg.get(node_info[lca_node].tot_pos, node_info[a].tot_pos - 1).mx);
        break;
      } else {
        int chain = node_info[a].chain_no;
        int h = chain_info[chain].head;
        res = max(res, sg.get(node_info[h].tot_pos, node_info[a].tot_pos - 1).mx);
        int p = node_info[h].par;
        assert(p != 0);
        res = max(res, cost[{min(h, p), max(h, p)}]);
        a = p;
      }
    }
    return res;
  };
  while (cin >> quer, quer != "DONE") {
    int a, b;
    cin >> a >> b;
    if (quer == "CHANGE") {
      int u = edges[a].first.first, v = edges[a].first.second;
      if (node_info[u].chain_no == node_info[v].chain_no) {
        if (node_info[u].chain_pos > node_info[v].chain_pos) {
          swap(u, v);
        }
        assert(node_info[v].chain_pos - node_info[u].chain_pos == 1);
        sg.modify(node_info[u].tot_pos, b);
      }
      G[u].erase({v, cost[{u, v}]});
      G[v].erase({u, cost[{u, v}]});
      edges[a].second = b;
      cost[{u, v}] = b;
      G[u].insert({v, b});
      G[v].insert({u, b});
    } else {
      int lca_node = lca(a, b);
      int res = max(get(a, lca_node), get(b, lca_node));
      assert(res != INT_MIN);
      cout << res << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    clear_data();
    test_case();
  }
  return 0;
}
