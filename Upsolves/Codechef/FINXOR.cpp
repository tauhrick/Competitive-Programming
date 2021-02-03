#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kQuestions = 20;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n;

  void Read() {
    cin >> n;
  }
 
  void Solve() {
    int sum = GetResponse(1, 1 << kQuestions);
    sum -= n * (1 << kQuestions);
    int xor_sum = sum & 1;
    for (int bit = kQuestions - 1; bit > 0; --bit) {
      int curr = GetResponse(1, 1 << bit);
      int ones = (n + ((sum - curr) >> bit)) >> 1;
      xor_sum |= (ones & 1) << bit;
    }
    GetResponse(2, xor_sum);
  }
  
  int GetResponse(int a, int b) {
    cout << a << ' ' << b << endl;
    int resp;
    cin >> resp;
    if (resp == -1) exit(0);
    return resp;
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