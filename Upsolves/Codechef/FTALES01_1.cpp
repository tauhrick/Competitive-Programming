#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;	
    cin >> n >> m;
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v, i + 1);
        G[v].emplace_back(u, i + 1);
    }
    int x;
    cin >> x;
    set<int> pos;
    for (int i = 0; i < x; ++i) {
        int y;
        cin >> y;
        pos.emplace(y);
    }
    vector<int> dep(n + 1);
    vector<bool> seen(n + 1);
    function<void(int, int)> pre = [&](int u, int d) {
        dep[u] = d;
        seen[u] = true;
        for (auto &v : G[u]) {
            if (!seen[v.first]) {
                pre(v.first, d + 1);
            }
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) {
            pre(i, 0);
        }
    }
    vector<int> dp(n + 1);
    fill(seen.begin(), seen.end(), false);
    int ans = 0;
    function<void(int, int, int)> dfs = [&](int u, int p, int e) {
        seen[u] = true;
        for (auto &w : G[u]) {
            int v = w.first;
            int ind = w.second;
            if (v == p) {
                continue;
            }
            if (!seen[v]) {
                dfs(v, u, ind);
                dp[u] += dp[v];
            } else {
                if (dep[v] < dep[u]) {
                    ++dp[u];
                } else {
                    --dp[u];
                }
            }
        }
        if (dp[u] == 0) {
            ans += pos.count(e);
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) {
            dfs(i, i, -1);
        }
    }
    cout << ans << "\n";
    return 0;
}

