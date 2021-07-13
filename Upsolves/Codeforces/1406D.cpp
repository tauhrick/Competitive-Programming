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
  vector<int> a;  
  vector<int64_t> diff;
  int q;
  vector<array<int, 3>> queries;
  int64_t sum;

  void Read() {
    cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    } 
    cin >> q;
    queries.resize(q);
    for (auto &qq : queries) {
      for (auto &i : qq) {
        cin >> i;
      }
    }
  }
 
  void Solve() {
    sum = a[1];
    diff.resize(n + 1);
    for (int i = 2; i <= n; ++i) {
      diff[i] = a[i] - a[i - 1];
      Add(i);
    }
    cout << GetAns(sum) << '\n';
    for (auto [l, r, x] : queries) {
      if (l == 1) {
        sum += x;
      } else {
        Remove(l);
        diff[l] += x;
        Add(l);
      }
      if (r + 1 <= n) {
        Remove(r + 1);
        diff[r + 1] -= x;
        Add(r + 1);
      }
      cout << GetAns(sum) << '\n';
    }
  }

  void Remove(int i) {
    if (diff[i] > 0) {
      sum -= diff[i];
    }
  }

  void Add(int i) {
    if (diff[i] > 0) {
      sum += diff[i];
    }
  }

  int64_t GetAns(int64_t x) {
    if (x < 0) {
      return x / 2;
    } else {
      return (x + 1) / 2;
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}