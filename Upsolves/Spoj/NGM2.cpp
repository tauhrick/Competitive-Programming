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
  vector<int> nums;  

  void Read() {
    cin >> n >> k;
    nums.resize(k);
    for (auto &i : nums) {
      cin >> i;
    } 
  }
 
  void Solve() {
    int64_t res = n;
    int total_masks = 1 << k;
    for (int mask = 1; mask < total_masks; ++mask) {
      int curr_taken = 0;
      int64_t curr_lcm = 0;
      for (int i = 0; i < k; ++i) {
        if ((mask >> i) & 1) {
          ++curr_taken;
          if (curr_lcm == 0) {
            curr_lcm = nums[i];
          } else {
            curr_lcm = (curr_lcm * nums[i]) / __gcd(curr_lcm, int64_t(nums[i]));
          }
        }
      }
      if (curr_taken & 1) {
        res -= n / curr_lcm;
      } else {
        res += n / curr_lcm;
      }
    }
    cout << res << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}