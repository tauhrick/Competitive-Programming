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

  void Read() {
    cin >> n >> k; 
  }
 
  void Solve() {
    for (int i = 0; i < n; ++i) {
      int r;
      if (i == 0) {
        r = Ask(i);
      } else {
        if (i & 1) {
          r = Ask(Xor(i - 1, i));
        } else {
          r = Ask(Xor(i, i - 1));
        }
      }
      if (r == -1) {
        exit(0);
      } else if (r == 1) {
        return;
      }
    }
  }

  vector<int> Get(int x) {
    vector<int> v;
    while (x > 0) {
      v.emplace_back(x % k);
      x /= k;
    }
    return v;
  }

  int Xor(int x, int y) {
    vector<int> places_x = Get(x);
    vector<int> places_y = Get(y);
    int ind = 0;
    int ans = 0;
    int p = 1;
    while (ind < int(max(places_x.size(), places_y.size()))) {
      int sum = 0;
      if (ind < int(places_x.size())) {
        sum += places_x[ind];
      }
      if (ind < int(places_y.size())) {
        sum -= places_y[ind];
      }
      ans += p * ((sum % k + k) % k);
      p *= k;
      ++ind;
    }
    return ans;
  }

  int Ask(int y) {
    cout << y << endl;
    int r;
    cin >> r;
    return r;
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