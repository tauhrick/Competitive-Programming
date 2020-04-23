#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, h;
    cin >> n >> h;
    vector<int> A(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> A[i];
    }
    int mx = 0;
    for (int k = 1; k <= n; ++k) {
        sort(A.begin() + 1, A.begin() + 1 + k);
        long long req = 0;
        for (int i = k; i >= 1; i -= 2) {
            req += A[i];
        }
        if (req > h) {
            break;
        }
        mx = k;
    }
    cout << mx << "\n";
    return 0;
}

