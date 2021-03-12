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
  double k;
  string s, t;
  map<char, int> cnt;

  void Read() {
    cin >> k >> s >> t;
  }
 
  void Solve() {
    for (int i = 0; i < 4; ++i) {
      ++cnt[s[i]];
      ++cnt[t[i]];
    }
    double possibilities = 0;
    double good = 0;
    for (char lst_s = '1'; lst_s <= '9'; ++lst_s) {
      s[4] = lst_s;
      double ways_s = k - cnt[lst_s];
      ++cnt[lst_s];
      for (char lst_t = '1'; lst_t <= '9'; ++lst_t) {
        t[4] = lst_t;
        double ways_t = k - cnt[lst_t];
        ++cnt[lst_t];
        if (Valid()) {
          possibilities += ways_s * ways_t;
          if (Score(s) > Score(t)) {
            good += ways_s * ways_t;
          }
        }
        --cnt[lst_t];
      }
      --cnt[lst_s];
    }
    cout << fixed << setprecision(10) << good / (1.0 * possibilities) << '\n';
  }

  bool Valid() {
    for (auto p : cnt) {
      if (p.second > k) return false;
    }
    return true;
  }

  int Score(string &x) {
    int res = 0;
    for (char c = '1'; c <= '9'; ++c) {
      int exp = 1;
      for (auto &ch : x) {
        if (ch == c) {
          exp *= 10;
        }
      }
      res += (c - '0') * exp;
    }
    return res;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}