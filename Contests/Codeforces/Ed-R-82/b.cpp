#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, g, b;
        cin >> n >> g >> b;
        int req = (n + 1) / 2;
        int ind = (req + g - 1) / g;
        long long ans = 1LL * (ind - 1) * b + req;
        long long rem = max(0LL, n - req - 1LL * (ind - 1) * b);
        cout << ans + rem << "\n";
    }
    return 0;
}
