#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<vector<int>> bad(n + 1);
    for (int i = 1; i <= k; ++i) {
        int u, v;
        cin >> u >> v;
        bad[u].emplace_back(v);
        bad[v].emplace_back(u);
    }
    vector<bool> seen(n + 1);
    vector<int> nodes;
    vector<int> ans(n + 1);
    function<void(int)> get_cc_nodes = [&](int u) {
        nodes.emplace_back(u);
        seen[u] = true;
        for (auto &v : G[u]) {
            if (!seen[v]) {
                get_cc_nodes(v);
            }
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (!seen[i]) {
            get_cc_nodes(i);
            sort(nodes.begin(), nodes.end());
            for (auto &u : nodes) {
                int cc = nodes.size() - 1 - G[u].size();
                for (auto &b : bad[u]) {
                    if (binary_search(nodes.begin(), nodes.end(), b)) {
                        --cc;
                    }
                }
                ans[u] = cc;
            }
            nodes.clear();
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << ans[i] << " \n"[i == n];
    }
    return 0;
}

