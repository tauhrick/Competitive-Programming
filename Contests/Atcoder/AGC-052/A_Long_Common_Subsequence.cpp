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
  int n;
  array<string, 3> s;
  vector<int> take;
  vector<int> cnt;
  string res;

  void Read() {
    cin >> n;
    for (auto &i : s) {
      cin >> i;
      i += i;
    }
  }
 
  void Solve() {
    Generate(0, false);
    cout << res << '\n';
  }

  void Generate(int ind, bool done) {
    if (ind == 3) {
      if (!done || !res.empty()) return;
      bool ok = true;
      for (auto &i : s) {
        int t = 0, c = 0;
        for (int j = 0; j < int(i.size()) && t < 3; ++j) {
          if (i[j] - '0' == take[t]) {
            ++c;
            if (c == cnt[t]) {
              ++t;
              c = 0;
            }
          }
        }
        ok &= t == 3;
      }
      if (ok) {
        for (int i = 0; i < 3; ++i) {
          res += string(cnt[i], char('0' + take[i]));
        }
      }
    } else {
      vector cand_cnt = {n};
      if (!done) {
        cand_cnt.push_back(1);
      }
      for (auto t : {0, 1}) {
        for (auto c : cand_cnt) {
          take.emplace_back(t);
          cnt.emplace_back(c);
          Generate(ind + 1, done || (c == 1));
          take.pop_back();
          cnt.pop_back();
        }
      }
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    Task t;
    t.Perform();
  }
  return 0;
}