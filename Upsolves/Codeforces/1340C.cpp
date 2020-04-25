#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> D(m);
    for (int i = 0; i < m; ++i) {
        cin >> D[i];
    }
    sort(D.begin(), D.end());
    int g, r;
    cin >> g >> r;
    auto dist = vector(m, vector(g, INT_MAX));
    deque<pair<int, int>> Q;
    Q.push_back({0, 0});
    dist[0][0] = 0;
    while (!Q.empty()) {
        auto [u, gg] = Q.front();
        Q.pop_front();
        for (auto v : {u - 1, u + 1}) {
            if (v < 0 || v >= m) {
                continue;
            }
            int d = gg + abs(D[v] - D[u]);
            if (d > g) {
                continue;
            }
            d %= g;
            if (dist[v][d] != INT_MAX) {
                continue;
            }
            dist[v][d] = dist[u][gg];
            if (d == 0) {
                ++dist[v][d];
                Q.push_back({v, d});
            } else {
                Q.push_front({v, d});
            }
        }
    }
    long long answer = LLONG_MAX;
    for (int i = 0; i < m; ++i) {
        if (dist[i][0] != INT_MAX && n - D[i] <= g) {
            answer = min(answer, 1LL * dist[i][0] * (g + r) + n - D[i]);
        }
    }
    if (answer == LLONG_MAX) {
        answer = -1;
    }
    cout << answer << "\n";
    return 0;
}

