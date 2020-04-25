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
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        vector<int> is_peak(n);
        for (int i = 1; i < n - 1; ++i) {
            is_peak[i] = A[i - 1] < A[i] && A[i] > A[i + 1];
        }
        int t = accumulate(is_peak.begin() + 1, is_peak.begin() + k - 1, 0);
        int l = 0;
        int peaks = t;
        for (int i = k; i < n; ++i) {
            peaks += is_peak[i - 1] - is_peak[i - k + 1];
            if (peaks > t) {
                t = peaks;
                l = i - k + 1;
            }
        }
        cout << t + 1 << " " << l + 1 << "\n";
    }
    return 0;
}

