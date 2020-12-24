#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "Library/Debug.cpp"
#else
#define debug(...) 42
#endif

struct Node {
  int close, open, score;
};

class Task {
 private:
  string s;
  int m;
  vector<pair<int, int>> queries;
  int n;
  vector<Node> sg_tree;

  void Read() {
    cin >> s >> m;
    queries.resize(m);
    for (auto &[l, r] : queries) {
      cin >> l >> r;
    }
    n = int(s.size());
    s = " " + s;
  }
 
  void Solve() {
    sg_tree.resize(4 * n + 4);
    Build(1, 1, n);
    for (auto &[l, r] : queries) {
      cout << 2 * Get(1, 1, n, l, r).score << "\n";
    }
  }

  void Build(int tv, int tl, int tr) {
    if (tl == tr) {
      sg_tree[tv] = Node{s[tl] == ')', s[tl] == '(', 0};
    } else {
      int tm = ((tl + tr) >> 1), lc = 2 * tv, rc = lc + 1;
      Build(lc, tl, tm);
      Build(rc, tm + 1, tr);
      sg_tree[tv] = Merge(sg_tree[lc], sg_tree[rc]);
    }
    debug(tl, tr, sg_tree[tv].open, sg_tree[tv].close, sg_tree[tv].score);
  }

  Node Get(int tv, int tl, int tr, int ql, int qr) {
    if (qr < tl || ql > tr) {
      return Node{0, 0, 0};
    } else if (ql <= tl && tr <= qr) {
      return sg_tree[tv];
    } else {
      int tm = ((tl + tr) >> 1), lc = 2 * tv, rc = lc + 1;
      return Merge(Get(lc, tl, tm, ql, qr), Get(rc, tm + 1, tr, ql, qr));
    }
  }

  Node Merge(Node a, Node b) {
    return Node{
      a.close + max(0, b.close - a.open),
      b.open + max(0, a.open - b.close),
      a.score + b.score + min(a.open, b.close)
    };
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  Task t;
  t.Perform();
  return 0;
}