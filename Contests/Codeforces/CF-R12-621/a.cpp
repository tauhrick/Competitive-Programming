#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, d;
        cin >> n >> d;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        int mx = A[0];
        for (int i = 1; i < n; ++i) {
            int ded = min(A[i], d / i);
            mx += ded;
            d -= ded * i;
        }
        cout << mx << "\n";
    }
    return 0;
}

