#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;	
    cin >> n >> m >> k;
    vector<vector<tuple<int, int, int>>> G(n + 1);
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].emplace_back(v, w, INT_MAX);
        G[v].emplace_back(u, w, INT_MAX);
    }
    for (int i = 1; i <= k; ++i) {
        int v, w;
        cin >> v >> w;
        G[1].emplace_back(v, w, i);
        G[v].emplace_back(1, w, i);
    }
    vector<long long> min_dist(n + 1, LLONG_MAX);
    vector<bool> seen(n + 1);
    min_dist[1] = 0;
    priority_queue<tuple<long long, int, int>> pq;
    pq.push({0, 1, INT_MAX});
    vector<bool> unvis(k + 1, true);
    while (!pq.empty()) {
        auto [w, u, ind] = pq.top();
        pq.pop();
        w *= -1;
        if (seen[u]) {
            continue;
        }
        seen[u] = true;
        if (ind != INT_MAX) {
            unvis[ind] = false;
        }
        min_dist[u] = w;
        for (auto &[v, w_nxt, e] : G[u]) {
            if (seen[v]) {
                continue;
            }
            long long curr_dist = w + w_nxt;
            if (curr_dist < min_dist[v]) {
                pq.push({-curr_dist, v, e});
            }
        }
    }
    cout << accumulate(unvis.begin() + 1, unvis.end(), 0) << "\n";
    return 0;
}

