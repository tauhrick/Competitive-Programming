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
  int n, m;
  vector<string> graph;
  vector<int> res;
  string path;

  void Read() {
    cin >> n >> m;
    graph.resize(n);
    for (auto &row : graph) {
      cin >> row;
    }
  }
 
  void Solve() {
    if (m == 1) {
      res = {0, 1};
    } else {
      Try();
    }
    if (int(res.size()) == m + 1) {
      cout << "YES\n";
      for (auto &node : res) {
        cout << node + 1 << ' ';
      }
      string rev_path = path;
      reverse(rev_path.begin(), rev_path.end());
      assert(rev_path == path);
    } else {
      cout << "NO";
    }
    cout << '\n';
  }

  void Try() {
    if (CheckEqual()) return;
    if (n == 2) {
      if (m % 2 == 0) return;
      vector nodes = {0, 1};
      for (int i = 0; i <= m; ++i) {
        Move(nodes[i % 2]);
      }
      return;
    }
    DoHalf(0);
    int good_node = GetGoodNode();
    if (!res.empty() && good_node == res.back()) {
      path.clear();
      res.clear();
      DoHalf(1);
      assert(good_node != res.back());
    }
    Move(good_node);
    map<char, int> nxt;
    for (int v = 0; v < n; ++v) {
      nxt[graph[good_node][v]] = v;
    }
    while (int(path.size()) < m) {
      Move(nxt[GetDirection()]);
      if (int(path.size()) < m) {
        Move(good_node);
      }
    }
  }

  void DoHalf(int st) {
    int random = (m - 1) / 2;
    vector<int> nodes = {st, !st};
    for (int i = 0; i <= random; ++i) {
      Move(nodes[i % 2]);
    }
  }

  bool CheckEqual() {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (graph[i][j] == graph[j][i]) {
          vector nodes = {i, j};
          for (int k = 0; k <= m; ++k) {
            Move(nodes[k % 2]);
          }
          return true;
        }
      }
    }
    return false;
  }

  void Move(int x) {
    if (!res.empty()) {
      path += graph[res.back()][x];
    }
    res.push_back(x);
  }

  int GetGoodNode() {
    for (int i = 0; i < n; ++i) {
      string out = graph[i];
      string in;
      for (int j = 0; j < n; ++j) {
        in += graph[j][i];
      }
      if (Check(out) && Check(in)) {
        return i;
      }
    }
    assert(false);
  }

  bool Check(string &s) {
    int cnt_a = 0, cnt_b = 0;
    for (auto &ch : s) {
      cnt_a += ch == 'a';
      cnt_b += ch == 'b';
    }
    return cnt_a > 0 && cnt_b > 0;
  }

  char GetDirection() {
    int ind = m - int(path.size());
    return path[ind - 1];
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