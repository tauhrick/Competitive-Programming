#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<vector<int>> G(n + 1);
        for (int i = 1; i <= n; ++i) {
            int k;
            cin >> k;
            while (k--) {
                int v;
                cin >> v;
                G[i].emplace_back(v);
            }
        }
        int u = -1;
        set<int> rem;
        for (int i = 1; i <= n; ++i) {
            rem.insert(i);
        }
        for (int i = 1; i <= n; ++i) {
            sort(G[i].begin(), G[i].end());
            bool matched = false;
            for (auto &v : G[i]) {
                if (rem.count(v)) {
                    rem.erase(v);
                    matched = true;
                    break;
                }
            }
            if (!matched) {
                u = i;
            }
        }
        if (u == -1) {
            cout << "OPTIMAL\n";
        } else {
            cout << "IMPROVE\n" << u << " " << *rem.begin() << "\n";
        }
    }
    return 0;
}

