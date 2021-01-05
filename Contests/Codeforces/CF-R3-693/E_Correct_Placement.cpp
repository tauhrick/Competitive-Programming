#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

struct Rect {
  int h, w, idx;

  bool operator<(const Rect &o) const {
    return make_pair(h, w) < make_pair(o.h, o.w);
  }
};

class Task {
 private:
  int n;
  vector<Rect> hw;
 
  void Read() {
    cin >> n;
    hw.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> hw[i].h >> hw[i].w;
      hw[i].idx = i;
    }
  }
 
  void Solve() {
    sort(hw.begin(), hw.end());
    vector<int> pf_w_min(n);
    for (int i = 0; i < n; ++i) {
      pf_w_min[i] = min(hw[i].w, (i - 1 >= 0 ? pf_w_min[i - 1] : INT_MAX));
    }
    vector<int> ans(n, -1);
    for (auto rect : hw) {
      auto Find = [&](Rect x) -> void {
        int lo = 0;
        int hi = int(upper_bound(hw.begin(), hw.end(), Rect{x.h, -1, x.idx}) - hw.begin()) - 1;
        if (hi < lo) return;
        while (lo < hi) {
          int mid = lo + ((hi - lo) >> 1);
          if (pf_w_min[mid] < x.w) {
            hi = mid;
          } else {
            lo = mid + 1;
          }
        }
        if (pf_w_min[lo] < x.w) {
          ans[x.idx] = hw[lo].idx + 1;
        }
      };
      Find(Rect{rect.h, rect.w, rect.idx});
      if (ans[rect.idx] != -1) continue;
      Find(Rect{rect.w, rect.h, rect.idx});
    }
    for (auto &i : ans) {
      cout << i << " ";
    }
    cout << "\n";
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}