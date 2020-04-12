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
        vector<long long> A(n);
        vector<long long> B(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i] >> B[i];
        }
        long long answer = LLONG_MAX;
        long long tot = 0;
        for (int i = 0; i < n; ++i) {
            tot += max(0LL, A[(i + 1) % n] - B[i]);
        }
        for (int i = 0; i < n; ++i) {
            tot -= max(0LL, A[i] - B[(i - 1 + n) % n]);
            answer = min(answer, A[i] + tot);
            tot += max(0LL, A[i] - B[(i - 1 + n) % n]);
        }
        cout << answer << "\n";
    }
    return 0;
}

