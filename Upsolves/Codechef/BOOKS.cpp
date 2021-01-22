#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

struct Query {
  int l, r;
};

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n, m;
  vector<int> pages;
  vector<Query> queries;

  void Read() {
    cin >> n >> m;
    pages.resize(m + 1);
    for (int i = 1; i <= m; ++i) {
      cin >> pages[i];
    }
    queries.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> queries[i].l;
    }
    for (int i = 0; i < n; ++i) {
      cin >> queries[i].r;
    }
  }
 
  void Solve() {
    sort(pages.begin(), pages.end());
    vector<int64_t> pf_sum(m + 1);
    for (int i = 1; i <= m; ++i) {
      pf_sum[i] = pf_sum[i - 1] + pages[i];
    }
    for (auto &query : queries) {
      int st = int(lower_bound(pages.begin(), pages.end(), query.l) - pages.begin());
      int en = int(upper_bound(pages.begin(), pages.end(), query.r) - pages.begin()) - 1;
      cout << en - st + 1 << " " << pf_sum[en] - pf_sum[st - 1] << "\n";
    }
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}