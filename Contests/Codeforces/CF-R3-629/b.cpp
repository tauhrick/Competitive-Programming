#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        int p1, p2;
        for (int f = n - 2; f >= 0; --f) {
            int rem = n - 1 - f;
            if (k > rem) {
                k -= rem;
                continue;
            }
            p1 = f;
            p2 = n - 1 - (k - 1);
            break;
        }
        for (int i = 0; i < n; ++i) {
            if (i == p1 || i == p2) {
                cout << "b";
            } else {
                cout << "a";
            }
        }
        cout << "\n";
    }
    return 0;
}

