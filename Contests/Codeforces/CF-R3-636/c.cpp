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
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        long long sum = 0;
        for (int i = 0; i < n; ) {
            int mx = INT_MIN;
            while (i < n && A[i] > 0) {
                mx = max(mx, A[i++]);
            }
            if (mx != INT_MIN) {
                sum += mx;
            }
            int mn = INT_MIN;
            while (i < n && A[i] < 0) {
                mn = max(mn, A[i++]);
            }
            if (mn != INT_MIN) {
                sum += mn;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}

