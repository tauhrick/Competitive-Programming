#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int k;
        cin >> k;
        int n = 2 * k;
        vector<vector<pair<int, int>>> G(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            G[u].emplace_back(v, w);
            G[v].emplace_back(u, w);
        }
        long long mx = 0, mn = 0;
        vector<int> sub(n + 1);
        function<void(int, int)> dfs = [&](int u, int p) {
            sub[u] = 1;
            for (auto &[v, w] : G[u]) {
                if (v == p) {
                    continue;
                }
                dfs(v, u);
                sub[u] += sub[v];
                mn += (sub[v] % 2) * w;
                mx += 1LL * w * min(sub[v], n - sub[v]);
            }
        };
        dfs(1, 0);
        cout << mn << " " << mx << "\n";
    }
    return 0;
}

