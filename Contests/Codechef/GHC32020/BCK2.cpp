#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;	
    cin >> n;
    vector<vector<pair<int, int>>> G(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    vector<int> sub(n + 1);
    long long ans = 0;
    function<void(int, int)> pre = [&](int u, int par) {
        sub[u] = 1;
        for (auto &p : G[u]) {
            int v = p.first;
            int w = p.second;
            if (v != par) {
                pre(v, u);
                sub[u] += sub[v];
                ans += 2LL * w * min(sub[v], n - sub[v]);
            }
        }
    };
    pre(1, 1);
    cout << ans << "\n";
    return 0;
}

