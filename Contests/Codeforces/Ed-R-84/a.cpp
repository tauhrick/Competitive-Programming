#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        if (n % 2 != k % 2) {
            cout << "NO\n";
        } else {
            if (n < 1LL * k * k) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
    }
    return 0;
}

