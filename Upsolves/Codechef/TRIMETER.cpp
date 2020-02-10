#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> par;
vector<vector<int>> G;

void dfs(int u, int p, int dep, int &ans, int &max_dep) {
    par[u] = p;
    if (dep > max_dep) {
        max_dep = dep;
        ans = u;
    }
    for (auto &v : G[u]) {
        if (v != p) {
            dfs(v, u, dep + 1, ans, max_dep);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    G.assign(n + 1, {});
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    int a, b, mx;
    par.assign(n + 1, 0);
    dfs(1, 0, 0, a, mx = -1);
    dfs(a, 0, 0, b, mx = -1);
    int triameter = mx;
    if (mx != n - 1) {
        vector<bool> seen(n + 1);
        queue<int> q;
        int node = b;
        while (node != 0) {
            q.push(node);
            seen[node] = true;
            node = par[node];
        }
        int d = 0;
        int max_dist = -1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                node = q.front();
                q.pop();
                if (d > max_dist) {
                    max_dist = d;
                }
                for (auto &v : G[node]) {
                    if (!seen[v]) {
                        seen[v] = true;
                        q.push(v);
                    }
                }
            }
            ++d;
        }
        triameter += max_dist;
    }
    cout << triameter << "\n";
    return 0;
}

