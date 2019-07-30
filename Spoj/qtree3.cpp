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

    Node(int _mx = 0) : mx(_mx) {}

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
    if (qr < tl || tr < ql) {
      return Node();
    } else if (ql <= tl && tr <= qr) {
      return Tree[tv];
    } else {
      int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
      push(tv, lc, rc);
      return unite(get(lc, tl, tm, ql, qr), get(rc, tm + 1, tr, ql, qr));
    }
  }
  
  int find_first_knowingly(int tv, int tl, int tr, const function<bool(const Node&)>& f) {
    if (tl == tr) {
      return tl;
    } else {
      int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
      push(tv, lc, rc);
      if (f(Tree[lc])) {
        return find_first_knowingly(lc, tl, tm, f);
      } else {
        return find_first_knowingly(rc, tm + 1, tr, f);
      }
    }
  }
  
  int find_first(int tv, int tl, int tr, int ql, int qr, const function<bool(const Node&)>& f) {
    if (qr < tl || tr < ql) {
      return -1;
    } else if (ql <= tl && tr <= qr) {
      if (!f(Tree[tv])) {
        return -1;
      } else {
        return find_first_knowingly(tv, tl, tr, f);
      }
    } else {
      int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
      push(tm, lc, rc);
      int res = find_first(lc, tl, tm, ql, qr, f);
      if (res == -1) {
        res = find_first(rc, tm + 1, tr, ql, qr, f);
      }
      return res;
    }
  }
  
  int find_last_knowingly(int tv, int tl, int tr, const functin<bool(const Node&)>& f) {
    if (tl == tr) {
      return tl;
    } else {
      int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
      push(tm, lc, rc);
      if (f(Tree[rc])) {
        return find_last_knowingly(rc, tm + 1, tr);
      } else {
        return find_last_knowingly(lc, tl, tm);
      }
    }
  }
  
  int find_last(int tv, int tl, int tr, int ql, int qr, const function<bool(const Node&)>& f) {
    if (qr < tl || tr < ql) {
      return -1;
    } else if (ql <= tl && tr <= qr) {
      if (!f(Tree[tv])) {
        return -1;
      } else {
        return find_last_knowingly(tv, tl, tr, f);
      }
    } else {
      int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
      push(tm, lc, rc);
      int res = find_last(rc, tm + 1, tr, ql, qr, f);
      if (res == -1) {
        res = find_last(lc, tl, tm, ql, qr, f);
      }
      return res;
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
  
  int find_first(int ql, int qr, const function<bool(const Node&)>& f) {
    return find_first(1, 1, n, ql, qr, f);
  }
  
  int find_last(int ql, int qr, const function<bool(const Node&)>& f) {
    return find_last(1, 1, n, ql, qr, f);
  }
};

struct Chain {
  int head, sz;
  
  Chain() {
    head = sz = 0;
  }
};

struct Node {
  int chain_no, chain_pos, sub_sz, par, tot_pos, dep;
  
  Node() {
    chain_no = chain_pos = sub_sz = par = tot_pos = dep = 0;
  }
};

const int N = 1e5 + 10, LG = log2(N) + 2;

int n, q;
vector<vector<int>> G(N);
int curr_chain, ctr;
vector<Chain> chain_info(N);
vector<Node> node_info(N);
vector<int> order;

void pre_sz(int u, int p, int d) {
  node_info[u].sub_sz = 1;
  node_info[u].par = p;
  node_info[u].dep = d;
  for (auto v : G[u]) {
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
  for (auto v : G[u]) {
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
  for (auto v : G[u]) {
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
}

void test_case() {
  cin >> n >> q;
  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    G[u].emplace_back(v);
    G[v].emplace_back(u);
  }
  hld(1);
  vector<int> col(n + 1);
  Segment_tree sg(col);
  while (q--) {
    int typ, i;
    cin >> typ >> i;
    if (typ == 0) {
      col[i] ^= 1;
      sg.modify(node_info[i].tot_pos, col[i]);
    } else {
      int res = -1;
      while (true) {
        int chain = node_info[i].chain_no;
        int h = chain_info[chain].head;
        int pos = sg.find_first(node_info[h].tot_pos, node_info[i].tot_pos, [](auto foo) {
          return foo.mx == 1;
        });
        debug(i, pos);
        if (pos != -1) {
          res = order[pos];
        }
        i = node_info[h].par;
        if (i == 0) {
          break;
        }
      }
      cout << res << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}
