#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> A(n);
        int cp = 0;
        int cn = 0;
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
            cp += A[i] > 0;
            cn += A[i] < 0;
        }
        vector<int> B(n);
        for (int i = 0; i < n; ++i) {
            cin >> B[i];
        }
        bool ok = true;
        for (int i = n - 1; i >= 0; --i) {
            cp -= A[i] > 0;
            cn -= A[i] < 0;
            if (A[i] > B[i]) {
                ok = ok && (cn > 0);
            } else if (A[i] < B[i]) {
                ok = ok && (cp > 0);
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
    return 0;
}

