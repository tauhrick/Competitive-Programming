#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "../../Library/Debug.cpp"
#else
#define debug(...) 42
#endif

const int kBlockSize = int(sqrt(1e5));

struct Query {
  int l, r, idx;

  bool operator<(Query &o) const {
    return make_pair(l / kBlockSize, r) < make_pair(o.l / kBlockSize, o.r);
  }
};

class Task {
 private:
  static const int kA = int(1e7);

  int n, qq;
  vector<int> a;
  vector<Query> queries;
  vector<int> query_ans;
  vector<int> cnt;
  int cnt_even;
  int mx;

  void Read() {
    cin >> n >> qq;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
    queries.resize(qq);
    for (int i = 0; i < qq; ++i) {
      cin >> queries[i].l >> queries[i].r;
      queries[i].idx = i;
      if (queries[i].r < queries[i].l) {
        queries[i].r += n;
      }
      --queries[i].l;
      --queries[i].r;
    }
  }
 
  void Solve() {
    for (int i = 0; i < n; ++i) {
      a.emplace_back(a[i]);
    }
    cnt_even = 0;
    cnt.resize(kA + 1);
    query_ans.resize(qq);
    mo_s_algo(queries);
    for (auto &i : query_ans) {
      cout << i << "\n";
    }
  }

  void add(int pos) {
    if (pos < 0 || pos >= int(a.size())) return;
    if (cnt[a[pos]] != 0) {
      if (cnt[a[pos]] % 2 == 0) {
        --cnt_even;
      } else {
        ++cnt_even;
      }
    }
    ++cnt[a[pos]];
  }

  void remove(int pos) {
    if (pos < 0 || pos >= int(a.size())) return;
    --cnt[a[pos]];
    if (cnt[a[pos]] != 0) {
      if (cnt[a[pos]] % 2 == 1) {
        --cnt_even;
      } else {
        ++cnt_even;
      }
    }
  }

  void mo_s_algo(vector<Query>& quer) {
    sort(quer.begin(), quer.end());
    int curr_l = -1, curr_r = -1;
    for (auto& q: quer) {
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
      mx = max(mx, cnt_even);
      query_ans[q.idx] = cnt_even;
    }
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