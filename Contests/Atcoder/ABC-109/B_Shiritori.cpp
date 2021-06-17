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
  vector<string> words;  

  void Read() {
    cin >> n;
    words.resize(n);
    for (auto &word : words) {
      cin >> word;
    } 
  }
 
  void Solve() {
    set<string> done;
    string prv;
    for (auto &word : words) {
      if (done.count(word) || (!prv.empty() && word.front() != prv.back())) {
        cout << "No\n";
        return;
      }
      done.insert(word);
      prv = word;
    }
    cout << "Yes\n";
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}