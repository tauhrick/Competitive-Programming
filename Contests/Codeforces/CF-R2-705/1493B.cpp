#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const vector kRev = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int h, m;
  string s;

  void Read() {
    cin >> h >> m >> s;
  }
 
  void Solve() {
    int s_hrs = stoi(s.substr(0, 2));
    int s_mins = stoi(s.substr(3, 2));
    string res;
    int dist = INT_MAX;
    for (int c_hrs = 0; c_hrs < h; ++c_hrs) {
      for (int c_mins = 0; c_mins < m; ++c_mins) {
        int r_mins = GetReverse(GetLabel(c_hrs));
        int r_hrs = GetReverse(GetLabel(c_mins));
        if (0 <= r_mins && r_mins < m && 0 <= r_hrs && r_hrs < h) {
          int c_dist = GetDist(c_hrs, c_mins, s_hrs, s_mins);
          if (c_dist < dist) {
            dist = c_dist;
            res = GetLabel(c_hrs) + ":" + GetLabel(c_mins);
          }
        }
      }
    }
    cout << res << '\n';
  }

  int GetReverse(string x) {
    string res;
    bool valid = true;
    for (auto &ch : x) {
      int dig = int(ch - '0');
      if (kRev[dig] == -1) {
        valid = false;
        break;
      }
      res = char('0' + kRev[dig]) + res;
    }
    return valid ? stoi(res) : -1;
  }

  int GetDist(int c_hrs, int c_mins, int s_hrs, int s_mins) {
    int c_time = c_hrs * m + c_mins;
    int s_time = s_hrs * m + s_mins;
    int diff = c_time - s_time;
    if (diff < 0) {
      diff += h * m;
    }
    return diff;
  }

  string GetLabel(int x) {
    string x_str = to_string(x);
    while (int(x_str.size()) != 2) {
      x_str = "0" + x_str;
    }
    return x_str;
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