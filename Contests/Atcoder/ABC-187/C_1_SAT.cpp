#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug.cpp"
#else
#define debug(...) 42
#endif

class Task {
 private:
  int n;
  vector<string> s;
  map<pair<string, int>, int> cnt;

  void Read() {
    cin >> n;
    s.resize(n);
    for (auto &i : s) {
      cin >> i;
      int c = 0;
      if (i.front() == '!') {
        c = 1;
        i = i.substr(1);
      }
      ++cnt[{i, c}];
    }
  }
 
  void Solve() {
    for (auto p : cnt) {
      string t = p.first.first;
      if (cnt.count({t, !p.first.second})) {
        cout << t << "\n";
        return;
      }
    }
    cout << "satisfiable\n";
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  Task t;
  t.Perform();
  return 0;
}