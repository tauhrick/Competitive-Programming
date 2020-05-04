#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m, R, k;
    cin >> n >> m >> R >> k;
    priority_queue<tuple<long long, int, int>> pq;
    auto get_boxes = [&](int rr, int cc) {
        return 1LL * (min(n + 1, rr + R) - max(rr, R)) * (min(m + 1, cc + R) - max(cc, R));
    };
    set<pair<int, int>> done;
    for (int r = 1, c = (m + 1) / 2; r <= n; ++r) {
        pq.push({get_boxes(r, c), r, c});
        done.insert({r, c});
    }
    long long boxes = 0;
    while (k--) {
        auto [b, r, c] = pq.top();
        pq.pop();
        boxes += b;
        for (auto nxt : {c - 1, c + 1}) {
            if (1 <= nxt && nxt <= m && !done.count({r, nxt})) {
                done.insert({r, nxt});
                pq.push({get_boxes(r, nxt), r, nxt});
            }
        }
    }
    double answer = boxes / (1. * (n - R + 1) * (m - R + 1));
    cout << fixed << setprecision(10) << answer << '\n';
    return 0;
}

