#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        int mn = n * (a - b);
        int mx = n * (a + b);
        if (min(mx, c + d) - max(mn, c - d) >= 0) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        cout << "\n";
    }
    return 0;
}

