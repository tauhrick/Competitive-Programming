#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int a, b, c, n;
        cin >> a >> b >> c >> n;
        int mx = max({a, b, c});
        bool ans = true;
        for (auto el : {a, b, c}) {
            int req = mx - el;
            if (req > n) {
                ans = false;
            } else {
                n -= req;
            }
        }
        if (n % 3 != 0) {
            ans = false;
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}

