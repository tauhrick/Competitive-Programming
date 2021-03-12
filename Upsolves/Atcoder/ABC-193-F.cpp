#include <atcoder/maxflow>

#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

const int kInf = int(1.0e9);
const vector dr = {0, 0, 1, -1};
const vector dc = {1, -1, 0, 0};

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }

 private:
  int n;
  vector<string> grid;

  void Read() {
    cin >> n;
    grid.resize(n);
    for (auto &row : grid) {
      cin >> row;
    }
  }
 
  void Solve() {
    int source = n * n;
    int sink = n * n + 1;
    atcoder::mf_graph<int> flow_graph(sink + 1);
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
        int f_ind = r * n + c;
        char ch = grid[r][c];
        if (ch != '?') {
          if ((r + c) % 2 == 0) {
            ch ^= 'B' ^ 'W';
          }
          if (ch == 'B') {
            flow_graph.add_edge(source, f_ind, kInf);
          } else {
            flow_graph.add_edge(f_ind, sink, kInf);
          }
        }
        for (int d = 0; d < 4; ++d) {
          int n_r = r + dr[d];
          int n_c = c + dc[d];
          int n_f_ind = n_r * n + n_c;
          if (0 <= min(n_r, n_c) && max(n_r, n_c) < n) {
            flow_graph.add_edge(f_ind, n_f_ind, 1);
          }
        }
      }
    }
    cout << 2 * n * (n - 1) - flow_graph.flow(source, sink) << '\n';
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  Task t;
  t.Perform();
  return 0;
}