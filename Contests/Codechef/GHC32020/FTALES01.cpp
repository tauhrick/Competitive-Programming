#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;	
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
    }
    int x;
    cin >> x;
    set<int> special;
    for (int i = 0; i < x; ++i) {
        int p;
        cin >> p;
        special.insert(p);
    }
    vector<bool> seen(n + 1);
    vector<int> tin(n + 1);
    vector<int> low(n + 1);
    int timer = 0;
    int ans = 0;
    function<void(int, int)> dfs = [&](int u, int par) {
        tin[u] = low[u] = timer++;
        seen[u] = true;
        for (auto &p : G[u]) {
            int v = p.first;
            int ind = p.second;
            if (v == par) {
                continue;
            }
            if (!seen[v]) {
                dfs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u] && special.count(ind)) {
                    ++ans;
                }
            } else {
                low[u] = min(low[u], low[v]);
            }
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) {
            dfs(i, i);
        }
    }
    cout << ans << "\n";
    return 0;
}

