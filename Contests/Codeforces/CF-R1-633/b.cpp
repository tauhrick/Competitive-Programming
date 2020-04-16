#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> G(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        ++deg[u];
        ++deg[v];
    }
    vector<int> dep(n + 1);
    vector<int> par(n + 1);
    function<void(int, int, int)> dfs = [&](int u, int p, int d) {
        dep[u] = d;
        par[u] = p;
        for (auto &v : G[u]) {
            if (v != p) {
                dfs(v, u, d + 1);
            }
        }
    };
    for (int i = 1; i <= n; ++i) {
        if (deg[i] != 1) {
            dfs(i, 0, 0);
            break;
        }
    }
    int mini = 1;
    int parity = -1;
    int non_leaves = n - 1;
    set<int> par_leaves;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] == 1) {
            if (parity == -1) {
                parity = dep[i] % 2;
            } else if (dep[i] % 2 != parity) {
                mini = 3;
            }
            --non_leaves;
            par_leaves.insert(par[i]);
        }
    }
    int maxi = non_leaves + par_leaves.size();
    cout << mini << " " << maxi << "\n";
    return 0;
}

