#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

const int kN = int(2e5);

string res;

void Pre() {
  res = "98";
  for (int i = 9; int(res.size()) < kN; (i += 1) %= 10) {
    res += char('0' + i);
  }
}

class Task {
 private:
  int n;
 
  void Read() {
    cin >> n;
  }
 
  void Solve() {
    cout << res.substr(0, n) << "\n";
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  Pre();
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}