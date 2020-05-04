#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "/home/chirag11032000/CP/Library/Debug/Debug.cpp"
#endif

const int L = 2e2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    auto dp = vector(L + 1, vector(n + 1, 0));
    for (int j = 1; j <= L; ++j) {
        for (int i = n; i >= 1; --i) {
            int nxt = i + A[i] + j;
            dp[j][i] = 1;
            if (nxt <= n) {
                dp[j][i] += dp[j][nxt];
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int p, k;
        cin >> p >> k;
        if (k <= L) {
            cout << dp[k][p];
        } else {
            int steps = 0;
            while (p <= n) {
                ++steps;
                p += A[p] + k;
            }
            cout << steps;
        }
        cout << "\n";
    }
    return 0;
}

