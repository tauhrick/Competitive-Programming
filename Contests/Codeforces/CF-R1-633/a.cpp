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
        vector<int> A(n + 1);
        int mx = INT_MIN;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            mx = max(mx, A[i]);
            int diff = mx - A[i];
            if (diff) {
                ans = max(ans, 32 - __builtin_clz(diff));
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

