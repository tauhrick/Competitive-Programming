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
  vector<int> p;
  vector<int> x;

  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
    p.resize(n);
    for (auto &i : p) {
      cin >> i;
    }
    x.resize(10);
    for (auto &i : x) {
      cin >> i;
    }
  }
 
  void Solve() {
    vector<int> cnt_tickets(2);
    vector<int64_t> sum_prices(2);
    for (int i = 0; i < n; ++i) {
      int person = a[i] % 2;
      ++cnt_tickets[person];
      sum_prices[person] += p[i] - x[a[i]];
    }
    if (cnt_tickets[0] == cnt_tickets[1] || min(cnt_tickets[0], cnt_tickets[1]) == 0) {
      cout << 0 << '\n';
      cout << sum_prices[1] << ' ' << sum_prices[0];
    } else {
      cout << 1 << '\n';
      int64_t sum = sum_prices[0] + sum_prices[1];
      int64_t virtual_sum = sum;
      if (cnt_tickets[0] < cnt_tickets[1]) {
        virtual_sum += (cnt_tickets[1] - cnt_tickets[0]) * 
                       (VirtualPrice(0) - VirtualTax(0));
      } else {
        virtual_sum += (cnt_tickets[0] - cnt_tickets[1]) * 
                       (VirtualPrice(1) - VirtualTax(1));
      }
      cout << sum << ' ' << virtual_sum;
    }
    cout << '\n';
  }

  int64_t VirtualPrice(int parity) {
    vector<vector<int>> group_prices(10);
    for (int i = 0; i < n; ++i) {
      if (a[i] % 2 == parity) {
        group_prices[a[i]].push_back(p[i]);
      }
    }
    int min_size = INT_MAX, min_digit = -1;
    for (int digit = 0; digit < 10; ++digit) {
      int new_size = int(group_prices[digit].size());
      if (new_size != 0 && new_size < min_size) {
        min_size = new_size;
        min_digit = digit;
      }
    }
    int64_t sum = accumulate(group_prices[min_digit].begin(), 
                             group_prices[min_digit].end(), 0LL);
    return sum / min_size;
  }

  int64_t VirtualTax(int parity) {
    int64_t num = 0;
    int den = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] % 2 == parity) {
        num += x[a[i]];
        ++den;
      }
    }
    return num / den;
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