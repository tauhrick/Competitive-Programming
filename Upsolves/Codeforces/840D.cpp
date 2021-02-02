/*
  https://codeforces.com/problemset/problem/840/D

  - For a range we need to keep track of k most occurring elements, answer will
    be one of them.
  - [l, r] = [l, mid] + [mid + 1, r]
  - Most occuring elements in [l, r] are surely one of those which are most 
    occuring in [l, mid] or [mid + 1, r]
*/

#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  struct Query {
    int l, r, k;
  };

  struct Node {
    vector<int> most_freq;
  };

  int n, q;
  vector<int> a;
  vector<Query> queries;
  vector<vector<int>> inds;
  vector<vector<Node>> sg_tree;
  int timer = 0;
  vector<int> col, cnt;

  void Read() {
    cin >> n >> q;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    queries.resize(q);
    for (auto &query : queries) {
      cin >> query.l >> query.r >> query.k;
    }
  }
 
  void Solve() {
    inds.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      inds[a[i]].push_back(i);
    }
    sg_tree.resize(4 * (n + 1));
    col.resize(n + 1);
    cnt.resize(n + 1);
    Build(1, 1, n);
    for (auto &query : queries) {
      cout << Get(1, 1, n, query.l, query.r, query.k) << "\n";
    }
  }

  void Build(int tv, int tl, int tr) {
    sg_tree[tv].resize(tr - tl + 1);
    if (tl == tr) {
      sg_tree[tv][0].most_freq = {a[tl]};
    } else {
      int tm = (tl + tr) >> 1, lc = 2 * tv, rc = lc + 1;
      Build(lc, tl, tm);
      Build(rc, tm + 1, tr);
      Preprocess(tm, tl - 1, -1, tv, tl);
      Preprocess(tm + 1, tr + 1, 1, tv, tl);
    }
  }
  
  void Preprocess(int st, int en, int d, int node, int offset) {
    ++timer;
    vector<int> mx_cnts;
    for (int i = st; i != en; i += d) {
      if (col[a[i]] != timer) {
        col[a[i]] = timer;
        cnt[a[i]] = 1;
        mx_cnts.push_back(a[i]);
      } else {
        ++cnt[a[i]];
        if (find(mx_cnts.begin(), mx_cnts.end(), a[i]) == mx_cnts.end()) {
          mx_cnts.push_back(a[i]);
        }
        for (int j = int(mx_cnts.size()) - 1; j > 0; --j) {
          if (cnt[mx_cnts[j]] > cnt[mx_cnts[j - 1]]) {
            swap(mx_cnts[j], mx_cnts[j - 1]);
          }
        }
      }
      if (int(mx_cnts.size()) > 5) {
        mx_cnts.pop_back();
      }
      sg_tree[node][i - offset].most_freq = mx_cnts;
    }
  }
  
  int Get(int tv, int tl, int tr, int ql, int qr, int qk) {
    if (tl == tr) {
      return a[tl];
    }
    int tm = (tl + tr) >> 1, lc = 2 * tv, rc = lc + 1;
    if (qr <= tm) {
      return Get(lc, tl, tm, ql, qr, qk);
    } else if (ql >= tm + 1) {
      return Get(rc, tm + 1, tr, ql, qr, qk);
    }
    int best = INT_MAX;
    int lower_limit = (qr - ql + 1) / qk;
    for (auto en : {ql, qr}) {
      for (auto &p : sg_tree[tv][en - tl].most_freq) {
        int c = int(upper_bound(inds[p].begin(), inds[p].end(), qr) -
                    lower_bound(inds[p].begin(), inds[p].end(), ql));
        if (c > lower_limit && p < best) {
          best = p;
        }
      }
    }
    return best == INT_MAX ? -1 : best;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}