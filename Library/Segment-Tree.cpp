class Segment_tree {
public:
  struct Node {
    //

    void apply() { //
      //
    }
  };

  Node o(); //

  Node unite(const Node& a, const Node& b) {
    //
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
    n = V.size();
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
      return o;
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
      return;
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