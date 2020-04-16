#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int nr, ng, nb;
        cin >> nr >> ng >> nb;
        vector<int> R(nr);
        for (int i = 0; i < nr; ++i) {
            cin >> R[i];
        }
        vector<int> G(ng);
        for (int i = 0; i < ng; ++i) {
            cin >> G[i];
        }
        vector<int> B(nb);
        for (int i = 0; i < nb; ++i) {
            cin >> B[i];
        }
        sort(R.begin(), R.end());
        sort(G.begin(), G.end());
        sort(B.begin(), B.end());
        auto get_cost = [&](int x, int y, int z) {
            int dxy = x - y;
            int dyz = y - z;
            int dzx = z - x;
            return 1LL * dxy * dxy + 1LL * dyz * dyz + 1LL * dzx * dzx;
        };
        auto get = [&](auto &a, auto &b, auto &c) {
            long long ans = LLONG_MAX;
            for (int i = 0; i < (int) a.size(); ++i) {
                int ib = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
                if (ib == 0) {
                    continue;
                }
                --ib;
                int ic = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
                if (ic == (int) c.size()) {
                    continue;
                }
                ans = min(ans, get_cost(a[i], b[ib], c[ic]));
            }
            return ans;
        };
        cout << min({get(R, G, B), get(G, R, B), get(B, R, G), get(R, B, G), get(G, B, R), get(B, G, R)}) << "\n";
    }
    return 0;
}

