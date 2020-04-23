#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<bool> is_university(n + 1);
    for (int i = 0; i < 2 * k; ++i) {
        int x;
        cin >> x;
        is_university[x] = true;
    }
    vector<vector<int>> G(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    vector<int> sub_size(n + 1);
    long long answer = 0;
    function<void(int, int)> dfs = [&](int u, int p) {
        sub_size[u] = is_university[u];
        for (auto &v : G[u]) {
            if (v == p) {
                continue;
            }
            dfs(v, u);
            sub_size[u] += sub_size[v];
        }
        answer += min(sub_size[u], 2 * k - sub_size[u]);
    };
    dfs(1, 0);
    cout << answer << "\n";
    return 0;
}

