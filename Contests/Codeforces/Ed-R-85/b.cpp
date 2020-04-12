#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, x;
        cin >> n >> x;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        sort(A.rbegin(), A.rend());
        long long sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if ((sum + A[i]) >= 1LL * x * (i + 1)) {
                sum += A[i];
                ++cnt;
            } else {
                break;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}

