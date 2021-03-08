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
  int n, k;
  string s;
  vector<int> cnt;
  int curr_groups;

  void Read() {
    cin >> n >> k >> s;
  }
 
  void Solve() {
    if (n % k != 0) {
      cout << -1;
    } else if (AlreadyValid()) {
      cout << s;
    } else {
      curr_groups = 0;
      for (char c = 'a'; c <= 'z'; ++c) {
        curr_groups += (cnt[c] + k - 1) / k;
      }
      for (int pf = n - 1; pf >= 0; --pf) {
        Update(s[pf], -1);
        for (char nxt = char(s[pf] + 1); nxt <= 'z'; ++nxt) {
          Update(nxt, 1);
          if (curr_groups <= n / k) {
            s[pf] = nxt;
            char put = 'z';
            for (int j = n - 1; j > pf; --j) {
              while (put > 'a' && cnt[put] % k == 0) {
                --put;
              }
              s[j] = put;
              ++cnt[put];
            }
            cout << s << '\n';
            return;
          }
          Update(nxt, -1);
        }
      }
    }
    cout << '\n';
  }

  bool AlreadyValid() {
    cnt = vector(256, 0);
    for (auto &ch : s) {
      ++cnt[ch];
    }
    bool ok = true;
    for (char c = 'a'; c <= 'z'; ++c) {
      ok &= cnt[c] % k == 0;
    }
    return ok;
  }

  void Update(char ch, int val) {
    curr_groups -= (cnt[ch] + k - 1) / k;
    cnt[ch] += val;
    curr_groups += (cnt[ch] + k - 1) / k;
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