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
  vector<int> a;
 
  void Read() {
    cin >> n;
    a.resize(n);
    for (auto &i : a) {
      cin >> i;
    }
  }
 
  void Solve() {
    vector<priority_queue<int>> elements(2);
    for (auto &i : a) {
      elements[i & 1].emplace(i);
    }
    vector<int64_t> score(2);
    for (int i = 0; i < n; ++i) {
      int turn = i & 1;
      int take;
      if (elements[!turn].empty()) {
        take = turn;
      } else if (elements[turn].empty()) {
        take = !turn;
      } else if (elements[turn].top() >= elements[!turn].top()) {
        take = turn;
      } else {
        take = !turn;
      }
      if (take == turn) {
        score[turn] += elements[turn].top();
        elements[turn].pop();
      } else {
        elements[!turn].pop();
      }
    }
    if (score[0] > score[1]) {
      cout << "Alice";
    } else if (score[0] < score[1]) {
      cout << "Bob";
    } else {
      cout << "Tie";
    }
    cout << "\n";
  }
 
 public:
  void Perform() {
    Read();
    Solve();
  }
};
 
int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int tc;
  cin >> tc;
  for (int tt = 1; tt <= tc; ++tt) {
    Task t;
    t.Perform();
  }
  return 0;
}