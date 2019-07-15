#include <bits/stdc++.h>
using namespace std;

string to_string(string s) {
  return '"' + s + '"';
}

string to_string(const char* s) {
  return to_string((string) s);
}

string to_string(bool b) {
  return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

const vector<int> dx = {1, -1, 0, 0, 0};
const vector<int> dy = {0, 0, 1, -1, 0};
const long long INF = 1e15;

struct edge
{
  long long to, flow, cap, cost, rev;
};

struct MinCostMaxFlow
{
  long long nodes;
  vector<long long> prio, curflow, prevedge, prevnode, q, pot;
  vector<bool> inqueue;
  vector<vector<edge> > graph;
  MinCostMaxFlow() {}

  MinCostMaxFlow(long long n): nodes(n), prio(n, 0), curflow(n, 0), prevedge(n, 0), prevnode(n, 0), q(n, 0), pot(n, 0), inqueue(n, 0), graph(n) {}

  void addEdge(long long source, long long to, long long capacity, long long cost)
  {
    edge a = {to, 0, capacity, cost, graph[to].size()};
    edge b = {source, 0, 0, -cost, graph[source].size()};
    graph[source].push_back(a);
    graph[to].push_back(b);
  }

  void bellman_ford(long long source, vector<long long> &dist)
  {
    fill(dist.begin(), dist.end(), INF);
    dist[source] = 0;
    long long qt=0;
    q[qt++] = source;
    for(long long qh=0;(qh-qt)%nodes!=0;qh++)
    {
      long long u = q[qh%nodes];
      inqueue[u] = false;
      for(auto &e : graph[u])
      {
        if(e.flow >= e.cap)
          continue;
        long long v = e.to;
        long long newDist = dist[u] + e.cost;
        if(dist[v] > newDist)
        {
          dist[v] = newDist;
          if(!inqueue[v])
          {
            inqueue[v] = true;
            q[qt++ % nodes] = v;
          }
        }
      }
    }
  }

  pair<long long, long long> minCostFlow(long long source, long long dest, long long maxflow)
  {
    bellman_ford(source, pot);
    long long flow = 0;
    long long flow_cost = 0;
    while(flow < maxflow)
    {
      priority_queue<pair<long long, long long>, vector<pair<long long, long long> >, greater<pair<long long, long long> > > q;
      q.push({0, source});
      fill(prio.begin(), prio.end(), INF);
      prio[source] = 0;
      curflow[source] = INF;
      while(!q.empty())
      {
        long long d = q.top().first;
        long long u = q.top().second;
        q.pop();
        if(d != prio[u])
          continue;
        for(long long i=0;i< (long long) graph[u].size();i++)
        {
          edge &e=graph[u][i];
          long long v = e.to;
          if(e.flow >= e.cap)
            continue;
          long long newPrio = prio[u] + e.cost + pot[u] - pot[v];
          if(prio[v] > newPrio)
          {
            prio[v] = newPrio;
            q.push({newPrio, v});
            prevnode[v] = u;
            prevedge[v] = i;
            curflow[v] = min(curflow[u], e.cap - e.flow);
          }
        }
      }
      if(prio[dest] == INF)
        break;
      for(long long i=0;i<nodes;i++)
        pot[i]+=prio[i];
      long long df = min(curflow[dest], maxflow - flow);
      flow += df;
      for(long long v=dest;v!=source;v=prevnode[v])
      {
        edge &e = graph[prevnode[v]][prevedge[v]];
        e.flow += df;
        graph[v][e.rev].flow -= df;
        flow_cost += df * e.cost;
      }
    }
    return {flow, flow_cost};
  }
};

void test_case() {
  long long n, m, z, t;
  cin >> n >> m >> z >> t;
  vector<vector<char>> G(n + 1, vector<char>(m + 1));
  vector<pair<long long, long long>> pos;
  for (long long i = 1; i <= n; ++i) {
    for (long long j = 1; j <= m; ++j) {
      cin >> G[i][j];
      if (G[i][j] == 'S') {
        pos.emplace_back(i, j);
      }
    }
  }
  vector<vector<vector<long long>>> fall(n + 1, vector<vector<long long>>(m + 1, vector<long long>(t + 1)));
  for (long long i = 0; i < z; ++i) {
    long long x, y, p, q, h;
    cin >> x >> y >> p >> q >> h;
    for (long long ctr = p; ctr < q; ++ctr) {
      fall[x][y][ctr] = max(fall[x][y][ctr], h);
    }
  }
  MinCostMaxFlow network(2 * (t + 3) * (n * m) + 1);
  auto get_ind = [&](auto timer, auto r, auto c, auto to_add) {
    long long prv_layers = 2 * timer + to_add;
    long long cur_layer_prv_rows = r - 1;
    long long ind = prv_layers * (n * m) + cur_layer_prv_rows * m + c;
    return ind;
  };
  for (long long timer = 1; timer <= t; ++timer) {
    for (long long r = 1; r <= n; ++r) {
      for (long long c = 1; c <= m; ++c) {
        //~ Add between layers
        if (G[r][c] == '#') {
          continue;
        }
        long long from_1 = get_ind(timer, r, c, 0);
        long long from_2 = get_ind(timer, r, c, 1);
        network.addEdge(from_1, from_2, 1, 0);
        for (long long dr = 0; dr < 5; ++dr) {
          long long _r = r + dy[dr];
          long long _c = c + dx[dr];
          if (_r >= 1 && _r <= n && _c >= 1 && _c <= m) {
            if (G[_r][_c] == '#') {
              continue;
            }
            long long to_1 = get_ind(timer + 1, _r, _c, 0);
            long long cost = 0;
            if (_r == r && _c == c) {
              cost = -fall[r][c][timer - 1];
            }
            network.addEdge(from_2, to_1, 1, cost);
          }
        }
      }
    }
  }
  for (auto p : pos) {
    long long from_1 = get_ind(0, 1, 1, 0);
    long long to_1 = get_ind(1, p.first, p.second, 0);
    network.addEdge(from_1, to_1, 1, 0);
  }
  for (long long r = 1; r <= n; ++r) {
    for (long long c = 1; c <= m; ++c) {
      if (G[r][c] == '#') {
        continue;
      }
      long long from_1 = get_ind(t + 1, r, c, 0);
      long long from_2 = get_ind(t + 1, r, c, 1);
      network.addEdge(from_1, from_2, 1, 0);
      long long to_1 = get_ind(t + 2, 1, 1, 0);
      network.addEdge(from_2, to_1, 1, 0);
    }
  }
  auto ans = network.minCostFlow(get_ind(0, 1, 1, 0), get_ind(t + 2, 1, 1, 0), INF);
  assert(ans.first == pos.size());
  cout << -ans.second << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  test_case();
  return 0;
}

//~ Attribution: https://github.com/Ashishgup1/Competitive-Coding/blob/master/Min%20Cost%20Max%20Flow%20-%20Dijkstra.cpp
