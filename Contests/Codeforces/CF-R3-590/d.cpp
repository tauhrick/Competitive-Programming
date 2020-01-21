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
    int sum;
    
    Node(int _sum = 0) : sum(_sum) {} //

    void apply(int x) { //
      sum += x;
    }
  };

  Node unite(const Node& a, const Node& b) {
    return Node(a.sum + b.sum);
  }

  void pull(int tv, int lc, int rc) {
    Tree[tv] = unite(Tree[lc], Tree[rc]);
  }

  void push(int tv, int lc, int rc) {
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
  
  int find_last_knowingly(int tv, int tl, int tr, const function<bool(const Node&)>& f) {
    if (tl == tr) {
      return tl;
    } else {
      int tm = tl + tr >> 1, lc = 2 * tv, rc = lc + 1;
      push(tm, lc, rc);
      if (f(Tree[rc])) {
        return find_last_knowingly(rc, tm + 1, tr, f);
      } else {
        return find_last_knowingly(lc, tl, tm, f);
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


void test_case() {
  string s;
  int q;
  cin >> s >> q;
  int n = s.size();
  s = " " + s;
  vector<Segment_tree> sg(26, Segment_tree(n));
  for (int i = 1; i <= n; ++i) {
    sg[s[i] - 'a'].modify(i, 1);
  }
  while (q--) {
    int typ;
    cin >> typ;
    if (typ == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      sg[s[pos] - 'a'].modify(pos, -1);
      sg[c - 'a'].modify(pos, 1);
      s[pos] = c;
    } else {
      int l, r;
      cin >> l >> r;
      int cnt = 0;
      for (int i = 0; i < 26; ++i) {
        cnt += sg[i].get(l, r).sum > 0;
      }
      cout << cnt << "\n";
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
