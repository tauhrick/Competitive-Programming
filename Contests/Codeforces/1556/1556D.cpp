#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const string kOr = "or";
const string kAnd = "and";

class Task {
 private:
  int n, k;  

  void Read() {
    cin >> n >> k; 
  }
 
  void Solve() {
    vector nums(n, 0);
    int or_01 = Ask(kOr, 0, 1);
    int or_12 = Ask(kOr, 1, 2);
    int or_02 = Ask(kOr, 0, 2);
    int and_01 = Ask(kAnd, 0, 1);
    int and_12 = Ask(kAnd, 1, 2);
    int and_02 = Ask(kAnd, 0, 2);
    for (int b = 0; b < 31; ++b) {
      int b_01 = (or_01 >> b) & 1;
      int b_12 = (or_12 >> b) & 1;
      int b_02 = (or_02 >> b) & 1;
      int min_b = min({b_01, b_12, b_02});
      int max_b = max({b_01, b_12, b_02});
      if (min_b == 1) {
        int a_01 = (and_01 >> b) & 1;
        int a_12 = (and_12 >> b) & 1;
        int a_02 = (and_02 >> b) & 1;
        if (a_01 == 0 && a_02 == 0) {
          nums[1] |= (1 << b);
          nums[2] |= (1 << b);
        } else if (a_12 == 0 && a_02 == 0) {
          nums[0] |= (1 << b);
          nums[1] |= (1 << b);
        } else if (a_12 == 0 && a_01 == 0) {
          nums[0] |= (1 << b);
          nums[2] |= (1 << b);
        } else {
          nums[0] |= (1 << b);
          nums[1] |= (1 << b);
          nums[2] |= (1 << b);
        }
      } else if (max_b == 0) {
      } else if (b_01 == 0) {
        nums[2] |= (1 << b);
      } else if (b_12 == 0) {
        nums[0] |= (1 << b);
      } else if (b_02 == 0) {
        nums[1] |= (1 << b);
      }
    }
    for (int i = 3; i < n; ++i) {
      int or_0i = Ask(kOr, 0, i);
      int and_0i = Ask(kAnd, 0, i);
      int xor_0i = (~and_0i) & (or_0i);
      nums[i] = xor_0i ^ nums[0];
    }
    sort(nums.begin(), nums.end());
    debug(nums);
    cout << "finish " << nums[k - 1] << endl;
  }

  int Ask(string op, int i, int j) {
    cout << op << ' ' << i + 1 << ' ' << j + 1 << endl;
    int resp;
    cin >> resp;
    return resp;
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Task t;
  t.Perform();
  return 0;
}
