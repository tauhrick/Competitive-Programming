#ifndef LOCAL
#include <bits/stdc++.h>
using namespace std;
#define debug(...) 42
#else
#include "Debug.hpp"
#endif

template <class Cap> struct mf_graph {
 public:
  mf_graph() : _n(0) {}
  mf_graph(int n) : _n(n), g(n) {}

  int add_edge(int from, int to, Cap cap) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    int m = int(pos.size());
    pos.push_back({from, int(g[from].size())});
    int from_id = int(g[from].size());
    int to_id = int(g[to].size());
    if (from == to) to_id++;
    g[from].push_back(_edge{to, to_id, cap});
    g[to].push_back(_edge{from, from_id, 0});
    return m;
  }

  struct edge {
    int from, to;
    Cap cap, flow;
  };

  edge get_edge(int i) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    auto _e = g[pos[i].first][pos[i].second];
    auto _re = g[_e.to][_e.rev];
    return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
  }

  std::vector<edge> edges() {
    int m = int(pos.size());
    std::vector<edge> result;
    for (int i = 0; i < m; i++) {
      result.push_back(get_edge(i));
    }
    return result;
  }

  void change_edge(int i, Cap new_cap, Cap new_flow) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    assert(0 <= new_flow && new_flow <= new_cap);
    auto &_e = g[pos[i].first][pos[i].second];
    auto &_re = g[_e.to][_e.rev];
    _e.cap = new_cap - new_flow;
    _re.cap = new_flow;
  }

  Cap flow(int s, int t) {
      return flow(s, t, std::numeric_limits<Cap>::max());
  }

  Cap flow(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);

    std::vector<int> level(_n), iter(_n);
    queue<int> que;

    auto bfs = [&]() {
      std::fill(level.begin(), level.end(), -1);
      level[s] = 0;
      while (!que.empty()) que.pop();
      que.push(s);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto e : g[v]) {
          if (e.cap == 0 || level[e.to] >= 0)
            continue;
          level[e.to] = level[v] + 1;
          if (e.to == t)
            return;
          que.push(e.to);
        }
      }
    };

    function<Cap(int, Cap)> dfs = [&](int v, Cap up) {
      if (v == s)
        return up;
      Cap res = 0;
      int level_v = level[v];
      for (int &i = iter[v]; i < int(g[v].size()); i++) {
        _edge &e = g[v][i];
        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0)
          continue;
        Cap d =
            dfs(e.to, std::min(up - res, g[e.to][e.rev].cap));
        if (d <= 0)
          continue;
        g[v][i].cap += d;
        g[e.to][e.rev].cap -= d;
        res += d;
        if (res == up)
          break;
      }
      return res;
    };

    Cap flow = 0;
    while (flow < flow_limit) {
      bfs();
      if (level[t] == -1)
        break;
      std::fill(iter.begin(), iter.end(), 0);
      while (flow < flow_limit) {
        Cap f = dfs(t, flow_limit - flow);
        if (!f) break;
        flow += f;
      }
    }
    return flow;
  }

  std::vector<bool> min_cut(int s) {
    std::vector<bool> visited(_n);
    queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int p = que.front();
      que.pop();
      visited[p] = true;
      for (auto e : g[p]) {
        if (e.cap && !visited[e.to]) {
          visited[e.to] = true;
          que.push(e.to);
        }
      }
    }
    return visited;
  }

private:
  int _n;
  struct _edge {
    int to, rev;
    Cap cap;
  };

  std::vector<std::pair<int, int>> pos;
  std::vector<std::vector<_edge>> g;
};

const int kApplications = 26;
const int kComputers = 10;

class Task {
 public:
  void Perform() {
    Read();
    Solve();
  }
 
 private:
  mf_graph<int> flow_graph;
  int source, sink;
  int total_applications;
  bool is_last = false;

  void Read() {
    source = 0;
    sink = kApplications + kComputers + 1;
    flow_graph = mf_graph<int>(sink + 1);
    total_applications = 0;
    while (true) {
      string line;
      if (!getline(cin, line)) {
        is_last = true;
        break;
      }
      if (line.empty()) break;
      int application = line[0] - 'A';
      int application_index = application + 1;
      int users = line[1] - '0';
      total_applications += users;
      flow_graph.add_edge(source, application_index, users);
      for (int i = 3; line[i] != ';'; ++i) {
        int computer = line[i] - '0';
        int computer_index = kApplications + computer + 1;
        flow_graph.add_edge(application_index, computer_index, 1);
      }
    }
    for (int i = 1; i <= 10; ++i) {
      flow_graph.add_edge(kApplications + i, sink, 1);
    }
  }
 
  void Solve() {
    int mf = flow_graph.flow(source, sink);
    if (mf != total_applications) {
      cout << "!\n";
      return;
    }
    string res(kComputers, '_');
    for (auto edge : flow_graph.edges()) {
      if (edge.flow == 1 && IsApplication(edge.from) && IsComputer(edge.to)) {
        res[edge.to - kApplications - 1] = char('A' + edge.from - 1);
      }
    }
    cout << res;
    if (is_last) exit(0);
    cout << '\n';
  }

  bool IsApplication(int x) {
    x -= 1;
    return 0 <= x && x <= 25;
  }

  bool IsComputer(int x) {
    x -= 1 + kApplications;
    return 0 <= x && x <= 9;
  }
};
 
int main() {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  while (true) {
    Task t;
    t.Perform();
  }
  return 0;
}
