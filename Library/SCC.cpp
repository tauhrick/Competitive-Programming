struct Scc {
  int v, group_cnt;
  vector<vector<int>> adj, radj;
  vector<int> group_num, vis;
  stack<int> stk;

  // v = number of vertices
  Scc(int _v): v(_v), group_cnt(0), group_num(_v), vis(_v), adj(_v), radj(_v) {}

  // Call this to add an edge (0-based)
  void add_edge(int v1, int v2) {
    adj[v1].eb(v2);
    radj[v2].eb(v1);
  }

  void fill_forward(int x) {
    vis[x] = true;
    for (int i = 0; i < (int) adj[x].size(); i++) {
      if (!vis[adj[x][i]]) {
        fill_forward(adj[x][i]);
      }
    }
    stk.push(x);
  }

  void fill_backward(int x) {
    vis[x] = false;
    group_num[x] = group_cnt;
    for (int i = 0; i < (int) radj[x].size(); i++) {
      if (vis[radj[x][i]]) {
        fill_backward(radj[x][i]);
      }
    }
  }

  // Returns number of strongly connected components.
  // After this is called, group_num contains component assignments (0-based)
  int get_scc() {
    for (int i = 0; i < v; i++) {
      if (!vis[i]) {
        fill_forward(i);
      }
    }
    group_cnt = 0;
    while (!stk.empty()) {
      if (vis[stk.top()]) {
        fill_backward(stk.top());
        ++group_cnt;
      }
      stk.pop();
    }
    return group_cnt;
  }
};