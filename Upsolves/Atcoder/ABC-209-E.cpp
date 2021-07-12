#include <atcoder/scc>

#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kN = 52 * 52 * 52;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  int n; 
  vector<string> s;
  vector<vector<int>> graph;
  vector<int> in;
  vector<int> state_type;

  void Read() {
    cin >> n;
    s.resize(n);
    for (auto &i : s) {
      cin >> i;
    } 
  }
 
  void Solve() {
    graph.resize(kN + 1);
    in.resize(kN + 1);
    for (auto &i : s) {
      int to = GetHash(i.substr(0, 3));
      int from = GetHash(i.substr(i.size() - 3));
      graph[from].push_back(to);
      ++in[to];
    }
    state_type = vector(kN + 1, -1);
    for (int i = 0; i <= kN; ++i) {
      if (in[i] == 0) {
        state_type[i] = 0;
        Dfs(i);
      }
    }
    for (auto &i : s) {
      int ans = state_type[GetHash(i.substr(i.size() - 3))];
      if (ans == 0) {
        cout << "Takahashi";
      } else if (ans == 1) {
        cout << "Aoki";
      } else {
        cout << "Draw";
      }
      cout << '\n';
    }
  }

  int GetHash(string t) {
    int res = 0;
    int pw = 1;
    for (int i = 0; i < 3; ++i) {
      res += pw * CharToDig(t[i]);
      pw *= 52;
    }
    return res;
  }

  int CharToDig(char ch) {
    if ('a' <= ch && ch <= 'z') {
      return ch - 'a';
    } else {
      return ch - 'A' + 26;
    }
  }

  void Dfs(int u) {
    for (auto &v : graph[u]) {
      if (state_type[v] != -1) continue;
      if (state_type[u] == 0) {
        state_type[v] = 1;
      } else if (--in[v] == 0) {
        state_type[v] = 0;
      } else {
        continue;
      }
      Dfs(v);
    }
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}