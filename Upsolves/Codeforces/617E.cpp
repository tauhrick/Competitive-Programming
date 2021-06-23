#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kBlockSize = int(sqrt(1.0e5));
const int kC = 1 << 20;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  struct Query {
    int l, r, idx;

    bool operator<(Query &o) const {
      return make_pair(l / kBlockSize, r) < make_pair(o.l / kBlockSize, o.r);
    }
  };

  int n, q, k;  
  vector<int> a;
  vector<Query> queries;
  vector<int> pf_xor;
  vector<int64_t> query_ans;
  vector<int> cnt;
  int64_t res;

  void Read() {
    cin >> n >> q >> k; 
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    queries.resize(q);
    for (int i = 0; i < q; ++i) {
      cin >> queries[i].l >> queries[i].r;
      --queries[i].l;
      queries[i].idx = i;
    }
  }
 
  void Solve() {
    pf_xor.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      pf_xor[i] = pf_xor[i - 1] ^ a[i];
    }
    mo_s_algo();
    for (auto &i : query_ans) {
      cout << i << '\n';
    }
  }

  void mo_s_algo() {
    res = 0;
    cnt.resize(kC + 1);
    query_ans.resize(q);
    sort(queries.begin(), queries.end());
    int curr_l = -1, curr_r = -1;
    for (auto &qq : queries) {
      while (curr_l > qq.l) {
        add(--curr_l);
      }
      while (curr_r < qq.r) {
        add(++curr_r);
      }
      while (curr_l < qq.l) {
        remove(curr_l++);
      }
      while (curr_r > qq.r) {
        remove(curr_r--);
      }
      query_ans[qq.idx] = solve_query();
    }
  }

  void add(int pos) {
    if (pos < 0 || pos > n) {
      return;
    }
    res += cnt[pf_xor[pos] ^ k];
    ++cnt[pf_xor[pos]];
  }

  void remove(int pos) {
    if (pos < 0 || pos > n) {
      return;
    }
    --cnt[pf_xor[pos]];
    res -= cnt[pf_xor[pos] ^ k];
  }

  int64_t solve_query() {
    return res;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}