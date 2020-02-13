#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.size();
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            ok &= (c[i] == a[i] || c[i] == b[i]);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}

