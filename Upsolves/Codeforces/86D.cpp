#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

int BLOCK_SZ;

struct Query {
  int l, r, idx;

  bool operator<(const Query &o) const {
    return make_pair(l / BLOCK_SZ, r) < make_pair(o.l / BLOCK_SZ, o.r);
  }
};

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n, t;
  vector<int> a;
  vector<Query> queries;
  vector<int64_t> query_ans;
  vector<int> cnt;
  int64_t sum;

  void Read() {
    cin >> n >> t;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
    BLOCK_SZ = int(sqrt(n));
    queries.resize(t);
    for (int i = 0; i < t; ++i) {
      queries[i].idx = i;
      cin >> queries[i].l >> queries[i].r;
      --queries[i].l, --queries[i].r;
    }
  }
 
  void Solve() {
    query_ans.resize(t);
    cnt.resize(*max_element(a.begin(), a.end()) + 1);
    sum = 0;
    mo_s_algo();
    for (auto &ans : query_ans) {
      cout << ans << "\n";
    }
  }

  void add(int pos) {
    if (pos < 0 || pos >= n) return;
    sum -= 1LL * a[pos] * cnt[a[pos]] * cnt[a[pos]];
    ++cnt[a[pos]];
    sum += 1LL * a[pos] * cnt[a[pos]] * cnt[a[pos]];
  }

  void remove(int pos) {
    if (pos < 0 || pos >= n) return;
    sum -= 1LL * a[pos] * cnt[a[pos]] * cnt[a[pos]];
    --cnt[a[pos]];
    sum += 1LL * a[pos] * cnt[a[pos]] * cnt[a[pos]];
  }

  int64_t solve_query() {
    return sum;
  }

  void mo_s_algo() {
    sort(queries.begin(), queries.end());
    int curr_l = -1, curr_r = -1;
    for (auto &q : queries) {
      while (curr_l > q.l) {
        add(--curr_l);
      }
      while (curr_r < q.r) {
        add(++curr_r);
      }
      while (curr_l < q.l) {
        remove(curr_l++);
      }
      while (curr_r > q.r) {
        remove(curr_r--);
      }
      query_ans[q.idx] = solve_query();
    }
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Task t;
  t.Perform();
  return 0;
}