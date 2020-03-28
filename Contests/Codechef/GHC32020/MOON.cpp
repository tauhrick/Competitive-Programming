#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        bool ok = false;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int xx = i * x + j * y;
                int yy = (n - i) * x + (m - j) * y;
                if (xx == yy) {
                    ok = true;
                }
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}

