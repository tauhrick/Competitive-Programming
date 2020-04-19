#include <bits/stdc++.h>

using namespace std;

void test_case() {
    int n;
    long long d;
    cin >> n >> d;
    vector<long long> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    for (int i = n - 1; i >= 0; --i) {
        d = min(d, (d / A[i]) * A[i]);
    }
    cout << d << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tc;
    cin >> tc;
    for (int tt = 1; tt <= tc; ++tt) {
        cout << "Case #" << tt << ": ";
        test_case();
    }
    return 0;
}

