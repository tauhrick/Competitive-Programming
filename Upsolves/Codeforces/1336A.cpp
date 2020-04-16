#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> G(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> dep(n + 1);
    vector<int> sub(n + 1);
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        dep[u] = d;
        sub[u] = 1;
        for (auto &v : G[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
                sub[u] += sub[v];
            }
        }
    };
    dfs(1, 0, 0);
    vector<int> contri(n + 1);
    for (int i = 1; i <= n; ++i) {
        contri[i] = dep[i] - (sub[i] - 1);
    }
    sort(contri.rbegin(), contri.rend() - 1);
    cout << accumulate(contri.begin() + 1, contri.begin() + k + 1, 0LL) << "\n";
    return 0;
}

