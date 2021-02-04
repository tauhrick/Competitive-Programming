#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int64_t kInf = INT64_MAX;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int typ;
  string s;
  int n;

  void Read() {
    cin >> typ >> s;
  }
 
  void Solve() {
    n = int(s.size());
    string cand1, cand2;
    for (int i = 0; i < n; ++i) {
      cand1 += (i % 2 == 0) ? 'B' : 'G';
      cand2 += (i % 2 == 0) ? 'G' : 'B';
    }
    int64_t ans = min(Get(cand1), Get(cand2));
    cout << (ans == kInf ? -1 : ans) << '\n';
  }

  int64_t Get(string &cand) {
    for (auto ch : "BG") {
      if (count(cand.begin(), cand.end(), ch) != count(s.begin(), s.end(), ch)) {
        return kInf;
      }
    }
    int64_t ans = 0;
    if (typ == 0) {
      for (int i = 0; i < n; ++i) {
        ans += cand[i] != s[i];
      }
      ans /= 2;
    } else {
      string t = s;
      map<char, set<int>> inds;
      for (int i = 0; i < n; ++i) {
        inds[t[i]].insert(i);
      }
      for (int i = 0; i < n; ++i) {
        int copy_ind = *inds[cand[i]].begin();
        inds[cand[i]].erase(copy_ind);
        if (copy_ind != i) {
          inds[t[i]].erase(i);
          inds[t[i]].insert(copy_ind);
          swap(t[i], t[copy_ind]);
          ans += copy_ind - i;
        }
      }
    }
    return ans;
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