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
        vector<int> diff(2 * k + 2);
        auto add = [&](int l, int r, int val) {
            diff[l] += val;
            diff[r + 1] -= val;
        };
        vector<int> cnt(2 * k + 1);
        for (int i = 0; i < n / 2; ++i) {
            int l = min(A[i] + 1, A[n - i - 1] + 1);
            int r = max(A[i] + k, A[n - i - 1] + k);
            add(l, r, 1);
            ++cnt[A[i] + A[n - i - 1]];
        }
        int mn = INT_MAX;
        for (int i = 1; i <= 2 * k; ++i) {
            diff[i] += diff[i - 1];
            mn = min(mn, diff[i] - cnt[i] + 2 * (n / 2 - diff[i]));
        }
        cout << mn << "\n";
    }
    return 0;
}

