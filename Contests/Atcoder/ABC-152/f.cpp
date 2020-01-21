#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> edges(n - 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        edges[i] = {u, v};
    }
    int m;
    cin >> m;
    vector<int> u(m);
    vector<int> v(m);
    for (int i = 0; i < m; ++i) {
        cin >> u[i] >> v[i];
    }
    int l = (n - 1) / 2;
    vector<long long> dp(1 << l);
    for (int mask = 0; mask < (1 << l); ++mask) {
        vector<vector<pair<int, int>> G(n);
        for (int i = 0; i < l; ++i) {
            int u = edges[i].first;
            int v = edges[i].second;
            if (mask & (1 << i)) {
                G[u].emplace_back(v, 1);
                G[v].emplace_back(u, 1);
            } else {
                G[u].emplace_back(v, 0);
                G[v].emplace_back(u, 0);
            }
        }
    }
    return 0;
}
