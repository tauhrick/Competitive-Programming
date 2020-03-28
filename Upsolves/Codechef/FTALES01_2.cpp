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
    vector<bool> seen(n + 1);
    vector<int> min_anc(n + 1);
    vector<int> tin(n + 1);
    int timer = 0;
    int ans = 0;
    function<void(int, int, int)> pre = [&](int u, int p, int e) {
        seen[u] = true;
        tin[u] = min_anc[u] = ++timer;
        for (auto &it : G[u]) {
            int v = it.first;
            int w = it.second;
            if (v == p) {
                continue;
            }
            if (seen[v]) {
                min_anc[u] = min(min_anc[u], tin[v]);
            } else {
                pre(v, u, w);
                min_anc[u] = min(min_anc[u], min_anc[v]);
            }
        }
        if (u != p && min_anc[u] == tin[u]) {
            ans += pos.count(e);
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) {
            pre(i, i, -1);
        }
    }
    cout << ans << "\n";
    return 0;
}

